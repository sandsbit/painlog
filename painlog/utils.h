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

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
//  Microsoft
    #if defined(SHARED_EXPORT)
        #define SHARED_EXPORT __declspec(dllexport)
    #else
        #define SHARED_EXPORT __declspec(dllimport)
    #endif
#elif defined(__linux__) || defined(UNIX) || defined(__unix__) || defined(LINUX)
//  GCC
    #if defined(SHARED_EXPORT)
        #define SHARED_EXPORT __attribute__((visibility("default")))
    #else
        #define SHARED_EXPORT
    #endif
#else
#define SHARED_EXPORT
#warning Unknown dynamic link import/export semantics.
#endif

#endif //PAINLOG_UTILS_H
