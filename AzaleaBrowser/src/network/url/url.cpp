#include <string>

#include <iostream>
#include "../protocols.h"
#include "url.h"
#include "../../third_party/ada/ada.h"
#include "../../third_party/ada/ada.cpp"

namespace URLParser {

	URL::URL(const std::string& URLString) : m_protocol{ getProtocol(URLString) }{
		
		// Ada cannot parse a URL if it does not have a protocol (e.g. google.com or has an empty protocol (e.g ://google.com)
		// To fix this, we change the URLString so it has the HTTPS protocol added by default, if it has no protocol specified

		switch (m_protocol) {
		case Protocol::DEFAULT:
			m_parsedURL = ada::parse("https://" + URLString); // Ada will handle any extra slashes
			break;
		case Protocol::EMPTY:
			m_parsedURL = ada::parse("https" + URLString);
			break;
		default:
			m_parsedURL = ada::parse(URLString);
			break;
		}

	}

	Protocol URL::getProtocol(const std::string& URLString) {
		// This gives us the protocol/scheme as an enum to make comparisons faster using switch-case statements

		size_t colonPosition{ URLString.find(":") };
		std::string_view protocol{ std::string_view(URLString).substr(0, colonPosition) };
		if (protocol == "http") return Protocol::HTTP;
		if (protocol == "https") return Protocol::HTTPS;
		if (protocol == "ftp") return Protocol::FTP;
		if (protocol == "ssh") return Protocol::SSH;
		if (protocol == "file") return Protocol::FILE;
		if (protocol.length() == 1) return Protocol::FILE;
		if (protocol.length() < URLString.length()) return Protocol::CUSTOM;
		if (protocol.length() == 0) return Protocol::EMPTY; // Special case where there is a colon, but no protocol was specified
		return Protocol::DEFAULT;
	}

	std::string_view URL::getURL() {
		return m_parsedURL->get_href();
	}

}