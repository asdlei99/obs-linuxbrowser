/*
Copyright (C) 2018 by Adrian Schollmeyer <nexadn@yandex.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <cstdint>
#include <map>
#include <string>

#include "shared.h"

class SplitMessage {
public:
	SplitMessage(const uint8_t id, const uint8_t size);
	~SplitMessage();

	SplitMessage operator=(const SplitMessage&) = delete;

	std::string getData() const;
	bool dataIsReady() const;

	void addMessage(const browser_message_t& msg);

private:
	std::map<uint8_t, std::string> messages;

	const uint8_t id;
	const uint8_t size;
};
