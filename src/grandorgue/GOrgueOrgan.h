/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2013 GrandOrgue contributors (see AUTHORS)
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

#ifndef GORGUEORGAN_H
#define GORGUEORGAN_H

#include <wx/wx.h>
#include "GOrgueMidiReceiver.h"

class GOrgueConfigReader;
class GOrgueConfigWriter;

class GOrgueOrgan
{
private:
	wxString m_ODF;
	wxString m_ChurchName;
	wxString m_OrganBuilder;
	wxString m_RecordingDetail;
	GOrgueMidiReceiver m_midi;

public:
	GOrgueOrgan(wxString odf, wxString church_name, wxString organ_builder, wxString recording_detail);
	GOrgueOrgan(GOrgueConfigReader& cfg, wxString group);
	virtual ~GOrgueOrgan();

	void Update(GOrgueOrgan* organ);

	void Save(GOrgueConfigWriter& cfg, wxString group);

	const wxString& GetODFPath();
	const wxString& GetChurchName();
	const wxString& GetOrganBuilder();
	const wxString& GetRecordingDetail();
	GOrgueMidiReceiver& GetMIDIReceiver();
	bool Match(const GOrgueMidiEvent& e);
};

#endif