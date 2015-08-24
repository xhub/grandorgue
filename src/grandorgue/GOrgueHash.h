/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2015 GrandOrgue contributors (see AUTHORS)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GORGUEHASH_H
#define GORGUEHASH_H

#include "contrib/sha1.h"
#include <wx/string.h>

typedef struct
{
	uint8_t hash[20];
} GOrgueHashType;

class GOrgueHash
{
private:
	SHA_CTX m_ctx;
	GOrgueHashType m_Hash;
	bool m_Done;

public:
	GOrgueHash();
	~GOrgueHash();

	const GOrgueHashType& getHash();
	wxString getStringHash();

	void Update(const void* data, unsigned len);
	void Update(const wxString& str);
	void Update(uint32_t value);
	void Update(int32_t value);
	void Update(int64_t value);
	void Update(uint64_t value);
};

#endif