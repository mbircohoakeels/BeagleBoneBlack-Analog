//
// Created by Michael Brookes on 21/05/2016.
/*
Copyright (C) 2016 Michael Brookes

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "iDeviceOverlay.h"

iDeviceOverlay::iDeviceOverlay( ) {
}

bool iDeviceOverlay::IsLoaded( const char* SearchFile ) {
    if( stat( SearchFile, &sb ) == 0 && S_ISREG( sb.st_mode ) )
        return true;
    return false;
}

bool iDeviceOverlay::Load( const char* Overlay ) {
    try {
        this->FileHandle = open( SLOTS_DIR, O_WRONLY );
        if( write( this->FileHandle, Overlay, 1024 ) > 0 ) {
            close( this->FileHandle );
            return true;
        }
        else
            return false;
    } catch( exception& e ) {
        cerr << "Exception : " << e.what() << endl;
    }
}