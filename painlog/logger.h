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

#ifndef PAINLOG_LOGGER_H
#define PAINLOG_LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils.h"

typedef struct logger_struct logger_t;

typedef enum {
    FATAL = 5,
    ERROR = 4,
    WARNING = 3,
    INFO = 2,
    DEBUG = 1,
    TRACE = 0,
    ALL = 0
} log_level_t;

typedef struct {
    void (*log_f)(logger_t *logger, log_level_t log_level, const char *message);
    void (*dispose)(void);
} logger_sink_t;

typedef struct logger_struct {
    char *app_name;
    char *logger_name;

    char *logging_format;
    log_level_t logging_level;
    logger_sink_t **logger_sinks;
} logger_t;

extern logger_t *default_logger;

/**
 * Initialize default logger.
 * Prints message to stderr on error.
 *
 * @param app_name The name of your application. Cannot be longer then 255 characters.
 */
SHARED_EXPORT void init_logging(const char *app_name);

#ifdef __cplusplus
};
#endif

#endif //PAINLOG_LOGGER_H
