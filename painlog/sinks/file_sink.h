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

#ifndef PAINLOG_FILE_SINK_H

#include "stdio.h"

#include "../structs.h"

typedef struct {
    logger_sink_t _logger_sink;

    FILE *fp;
} file_sink_t;

/**
 * Create logger sink for output in file.
 * Returns NULL on error.
 *
 * @param fp file pointer.
 * @return pointer to file_sink_t struct in dynamic memory converted to logger_sink_t *.
 */
SHARED_PUBLIC logger_sink_t *create_fp_sink(FILE *fp);
/**
 * Create logger sink for output in file.
 * Returns NULL on error.
 *
 * @param path path to file.
 * @return pointer to file_sink_t struct in dynamic memory converted to logger_sink_t *.
 */
SHARED_PUBLIC logger_sink_t *create_file_sink(const char *path);

inline logger_sink_t *create_stdout_sink() {
    return create_fp_sink(stdout);
}

inline logger_sink_t *create_stderr_sink() {
    return create_fp_sink(stderr);
}

SHARED_LOCAL void log_file_sink(logger_sink_t *sink, logger_t *logger, log_level_t log_level, const char *message);
SHARED_LOCAL void dispose_file_sink(logger_sink_t *sink);

#endif //PAINLOG_FILE_SINK_H
