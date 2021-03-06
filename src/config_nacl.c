/*
 * Copyright © 2013-2016  Rinat Ibragimov
 *
 * This file is part of FreshPlayerPlugin.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "config.h"
#include <stdlib.h>

const char *nacl_path_list[] = {
        "/opt/google/chrome",           // Chrome
        "/opt/google/chrome-beta",      // Chrome beta
        "/opt/google/chrome-unstable",  // Chrome unstable
        "/usr/lib64/chromium",          // Chromium (Slackware)
        "/usr/lib/chromium",            // Chromium (Slackware)
        NULL
};

const char **
fpp_config_get_plugin_path_list(void)
{
    return nacl_path_list;
}

const char *
fpp_config_get_default_plugin_version(void)
{
    return "1.0.0.0";
}

const char *
fpp_config_get_plugin_name(void)
{
    return "Native Client";
}

const char *
fpp_config_get_default_plugin_descr(void)
{
    return "Native Client";
}

const char *
fpp_config_get_plugin_mime_type(void)
{
    return "application/x-nacl::Native Client Executable;"
           "application/x-pnacl::Portable Native Client Executable";
}

char *
fpp_config_get_plugin_path(void)
{
    return NULL;
}

const char *
fpp_config_get_plugin_file_name(void)
{
    return "libppGoogleNaClPluginChrome.so";
}

uintptr_t
fpp_config_plugin_has_manifest(void)
{
    return 0;
}

void
fpp_config_detect_plugin_specific_quirks(void)
{
}
