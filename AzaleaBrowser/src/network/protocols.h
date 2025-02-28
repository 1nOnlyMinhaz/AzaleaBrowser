#pragma once

enum class Protocol {
	DEFAULT, // Protocol::DEFAULT is HTTPS as we want to have secure connections by default
	HTTP,
	HTTPS,
	FTP,
	SSH,
	FILE,
	CUSTOM,  // Used for custom protocols such as protocols used to open applications
	EMPTY // Special case where there is a colon, but no protocol was specified
};