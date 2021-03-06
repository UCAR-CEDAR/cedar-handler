// CedarTransmitter.cc

// This file is part of bes, A C++ back-end server implementation framework
// for the OPeNDAP Data Access Protocol.

// Copyright (c) 2004,2005 University Corporation for Atmospheric Research
// Author: Patrick West <pwest@ucar.edu> and Jose Garcia <jgarcia@ucar.edu>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// You can contact University Corporation for Atmospheric Research at
// 3080 Center Green Drive, Boulder, CO 80301
 
// (c) COPYRIGHT University Corporation for Atmospheric Research 2004-2005
// Please read the full copyright statement in the file COPYRIGHT_UCAR.
//
// Authors:
//      pwest       Patrick West <pwest@ucar.edu>
//      jgarcia     Jose Garcia <jgarcia@ucar.edu>

#include <iostream>

#include "CedarTransmitter.h"
#include <BESInfo.h>
#include <BESReturnManager.h>
#include <BESTransmitterNames.h>

CedarTransmitter::CedarTransmitter( )
    : _transmitter( 0 ), BESTransmitter()
{
}

BESTransmitter *
CedarTransmitter::get_transmitter( BESDataHandlerInterface &dhi )
{
    if( !_transmitter )
    {
	BESReturnManager *mgr = BESReturnManager::TheManager() ;
	if( dhi.transmit_protocol != "HTTP" )
	{
	    _transmitter = mgr->find_transmitter( BASIC_TRANSMITTER ) ;
	}
	else
	{
	    _transmitter = mgr->find_transmitter( "HTTP" ) ;
	}
    }
    return _transmitter ;
}

void
CedarTransmitter::send_text( BESInfo &info,
                             BESDataHandlerInterface &dhi )
{
    get_transmitter( dhi )->send_text( info, dhi ) ;
}

void
CedarTransmitter::send_html( BESInfo &info,
                             BESDataHandlerInterface &dhi )
{
    get_transmitter( dhi )->send_html( info, dhi ) ;
}

/** @brief dumps information about this object
 *
 * Displays the pointer value of this instance
 *
 * @param strm C++ i/o stream to dump the information to
 */
void
CedarTransmitter::dump( ostream &strm ) const
{
    strm << BESIndent::LMarg << "CedarTransmitter::dump - ("
			     << (void *)this << ")" << endl ;
    BESIndent::Indent() ;
    BESTransmitter::dump( strm ) ;
    BESIndent::UnIndent() ;
}

