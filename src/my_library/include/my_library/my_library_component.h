/**
MIT License

Copyright (c) 2017 Pontus Pohl

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#ifndef MY_LIBRARY_COMPONENT_H_
#define MY_LIBRARY_COMPONENT_H_

#include <stdio.h>
#include <string.h>

namespace mylibrary {
        
        class MyLibraryComponent {
            private:
	            /**
	             * Forbidden Copy Constructor
	             *
	             * @param obj Reference to an object of this class.
	             */
	            MyLibraryComponent(const MyLibraryComponent &/*obj*/);

	            /**
	             * Forbidden assignment operator
	             *
	             * @param obj Reference to an object of this class.
	             * @return Reference to this instance.
	             */
	            MyLibraryComponent& operator=(const MyLibraryComponent &/*obj*/);

            public:
	            /**
	             * Constructor.
	             *
	             */
	            MyLibraryComponent();

	            virtual ~MyLibraryComponent();
	            
        };
} // mylibrary

#endif /*MY_LIBRARY_COMPONENT_H_*/