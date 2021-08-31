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

#include "logger.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void init_logging(const char *app_name) {
    default_logger = (logger_t* ) malloc(sizeof(logger_t));
    if (default_logger == NULL)
        fputs("ERROR: Cannot initialize default logger for painlog! (malloc returned NULL)", stderr);

    default_logger->app_name = (char *) malloc(256);
    if (default_logger->app_name == NULL) {
        free(default_logger);
        fputs("ERROR: Cannot initialize default logger for painlog! (malloc returned NULL for app name string)", stderr);
    }
    strcpy(default_logger->app_name, app_name);
}
