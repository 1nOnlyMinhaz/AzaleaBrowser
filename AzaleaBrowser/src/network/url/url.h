// url.h
// Parses URLs using ada
#pragma once
#include <string>
#include "../protocols.h"
#include "../../third_party/ada/ada.h"

namespace URLParser {

	class URL {
	private:

		ada::result<ada::url_aggregator> m_parsedURL{};
		Protocol m_protocol{};

	public:

		URL(const std::string& URLString);

		Protocol getProtocol(const std::string& URLString);

		std::string_view getURL();

	};
}