/**
 *  PAINLOG PROJECT
 *  A logging library that isn't too simple, but, at the same time, isn't to much complicated.
 *  https://github.com/sandsbit/painlog/
 *
 *  painlog is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of
 *  the License, or (at your option) any later version.
 *
 *  painlog is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  and GNU Lesser General Public License along with painlog.  If not,
 *  see <https://www.gnu.org/licenses/>.
 */

#ifndef PAINLOG_UTILS_H
#define PAINLOG_UTILS_H

#if defined _WIN32 || defined __CYGWIN__
    #ifdef BUILD_SHARED
        #ifdef __GNUC__
            #define SHARED_PUBLIC __attribute__ ((dllexport))
        #else
            #define SHARED_LOCAL __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #else
        #ifdef __GNUC__
            #define SHARED_PUBLIC __attribute__ ((dllimport))
        #else
        #   define SHARED_LOCAL __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #endif
    #define DLL_LOCAL
#else
    #if __GNUC__ >= 4
        #define SHARED_PUBLIC __attribute__ ((visibility ("default")))
        #define SHARED_LOCAL  __attribute__ ((visibility ("hidden")))
    #else
        #define SHARED_PUBLIC
        #define SHARED_LOCAL
    #endif
#endif

#endif //PAINLOG_UTILS_H
