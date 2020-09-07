#include "restapi.h"

#include "jansson.h"
#include <cassert>
#include <chrono>
#include <thread> // sleep

#include <iostream>
#include <sstream>
#include <string>
#include <sstream>

namespace {

	// automatic init of curl's systems
	struct CurlStartup {
		CurlStartup() { curl_global_init(CURL_GLOBAL_ALL); }
		~CurlStartup() { curl_global_cleanup(); }
	}runCurlStartup;

	// internal helpers
	size_t recvCallback(void *contents, size_t size, size_t nmemb, void *userp) {
		//std::cout << "post_data" << std::endl;
		auto &buffer = *static_cast<std::string *> (userp);
		auto n = size * nmemb;
		return buffer.append((char*)contents, n), n;
	}

	json_t* doRequest(CURL *C,
		const std::string &url,
		const curl_slist *headers,
		std::ostream &log) {
		
		//jono
		//std::string foo =  headers;
		//std::cout << url << std::endl;
		
		//
		//std::string str = log.str();
		//const char* chr = str.c_str();
		//std::cout << chr << std::endl;

		//jono
		//std::cout << "==convert Methods ==" << std::endl;
		std::ostringstream ss;
		ss << log.rdbuf();
		
		// std::cout << ss.str().c_str() << std::endl;
		 ///////////////////////////////////
			
		std::string recvBuffer;
		curl_easy_setopt(C, CURLOPT_WRITEDATA, &recvBuffer);
		//std::cout << recvBuffer.c_str() << std::endl;

		curl_easy_setopt(C, CURLOPT_URL, url.c_str());
		curl_easy_setopt(C, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(C, CURLOPT_DNS_CACHE_TIMEOUT, 3600);

		goto curl_state;

	retry_state:
		//std::cout << "post_data" << std::endl;
		log << "  Retry in 2 sec..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		//std::cout << recvBuffer << std::endl; //jono
		recvBuffer.clear();
		curl_easy_setopt(C, CURLOPT_DNS_CACHE_TIMEOUT, 0);

	curl_state:
		CURLcode resCurl = curl_easy_perform(C);
		if (resCurl != CURLE_OK) {
			log << "Error with cURL: " << curl_easy_strerror(resCurl) << '\n'
				<< "  URL: " << url << '\n';

			goto retry_state;
		}

		/* documentation label */
		// json_state:
		json_error_t error;
		json_t *root = json_loads(recvBuffer.c_str(), 0, &error);


		//std::cout << recvBuffer.c_str() << std::endl;
		if (!root) {
			long resp_code;
			curl_easy_getinfo(C, CURLINFO_RESPONSE_CODE, &resp_code);
			log << "Server Response: " << resp_code << " - " << url << '\n'
				<< "Error with JSON: " << error.text << '\n'
				<< "Buffer:\n" << recvBuffer << '\n';

			goto retry_state;
		}

		return root;
	}
}

void RestApi::CURL_deleter::operator () (CURL *C) {
	//std::cout << "post_data" << std::endl;
	curl_easy_cleanup(C);
}

void RestApi::CURL_deleter::operator () (curl_slist *slist) {
	//std::cout << "post_data" << std::endl;
	curl_slist_free_all(slist);
}

RestApi::RestApi(string host, const char *cacert, std::ostream &log)
	: C(curl_easy_init()), host(std::move(host)), log(log) {
	//std::cout << "post_data 1" << std::endl;
	assert(C != nullptr);

	if (cacert)
		curl_easy_setopt(C.get(), CURLOPT_CAINFO, cacert);
	else  curl_easy_setopt(C.get(), CURLOPT_SSL_VERIFYPEER, false);

	curl_easy_setopt(C.get(), CURLOPT_CONNECTTIMEOUT, 10L);
	curl_easy_setopt(C.get(), CURLOPT_TIMEOUT, 20L);
	curl_easy_setopt(C.get(), CURLOPT_USERAGENT, "Blackbird");
	curl_easy_setopt(C.get(), CURLOPT_ACCEPT_ENCODING, "gzip");

	curl_easy_setopt(C.get(), CURLOPT_WRITEFUNCTION, recvCallback);
}

json_t* RestApi::getRequest(const string &uri, unique_slist headers) {
	//std::cout << "post_data 2" << std::endl;
	curl_easy_setopt(C.get(), CURLOPT_HTTPGET, true);


	//std::cout << headers.get() << std::endl;
	return doRequest(C.get(), host + uri, headers.get(), log);
}

json_t* RestApi::postRequest(const string &uri,
	unique_slist headers,
	const string &post_data) {
	//std::cout << "post_data 3" << std::endl;
	curl_easy_setopt(C.get(), CURLOPT_POSTFIELDS, post_data.data());
	curl_easy_setopt(C.get(), CURLOPT_POSTFIELDSIZE, post_data.size());
	// std::cout << post_data.data() << std::endl;
	// std::cout << "post_data.data()" << std::endl;
	return doRequest(C.get(), host + uri, headers.get(), log);
}

json_t* RestApi::postRequest(const string &uri, const string &post_data) {
	//std::cout << "pstData 4"+ post_data << std::endl;
	return postRequest(uri, nullptr, post_data);
}
