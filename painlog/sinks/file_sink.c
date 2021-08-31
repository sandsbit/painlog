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

#include "file_sink.h"

#include "stdlib.h"
#include "stdio.h"

logger_sink_t *create_fp_sink(FILE *fp) {
    file_sink_t *file_sink = (file_sink_t *) malloc(sizeof(file_sink_t));
    if (file_sink == NULL)
        return NULL;

    file_sink->_logger_sink.log_f = &log_file_sink;

    file_sink->fp = fp;
    return (logger_sink_t *) file_sink;
}

logger_sink_t *create_file_sink(const char *path) {
    FILE *fp = fopen(path, "w");
    if (fp == NULL)
        return NULL;

    return create_fp_sink(fp);
}


void log_file_sink(logger_sink_t *sink, logger_t *logger, log_level_t log_level, const char *message) {
    fputs(message, ((file_sink_t *)sink)->fp);
}

void dispose_file_sink(logger_sink_t *sink) {
    file_sink_t *file_sink = (file_sink_t *) sink;
    fclose(file_sink->fp);
    free(file_sink);
}
