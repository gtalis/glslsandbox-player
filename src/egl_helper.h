/*
 * EGL helper function definitions
 */

/*
 * This program is distributer under the 2-clause BSD license.
 * See at the end of this file for details.
 */

#ifndef EGL_HELPER_H
#define EGL_HELPER_H

#include <EGL/egl.h>

#include "native_gfx.h"

typedef struct egl_s egl_t;
struct egl_s {
  EGLint major;
  EGLint minor;

  int width;
  int height;

  EGLSurface surf;
  EGLDisplay dpy;
  EGLContext ctx;

  native_gfx_t *native_gfx;
};

void
clean_egl(egl_t *egl);

egl_t *
init_egl(int width, int height);

int
_egl_no_error(const char *file, int line);

#define egl_no_error()  _egl_no_error(__FILE__, __LINE__)

#define XEGL_STRICT 1

#if defined(XEGL_STRICT)

void
__xegl_check_error(const char *file, int line, const char *func);

EGLDisplay
__xegl_eglGetDisplay(const char *file, int line,
                     EGLNativeDisplayType display_id);

EGLBoolean
__xegl_eglChooseConfig(const char *file, int line,
                       EGLDisplay dpy, const EGLint *attrib_list,
                       EGLConfig *configs, EGLint config_size, EGLint *num_config);

EGLContext
__xegl_eglCreateContext(const char *file, int line,
			EGLDisplay dpy, EGLConfig config, EGLContext share_context,
			const EGLint *attrib_list);

EGLSurface
__xegl_eglCreateWindowSurface(const char *file, int line,
			      EGLDisplay dpy, EGLConfig config,
			      EGLNativeWindowType win, const EGLint *attrib_list);

EGLBoolean
__xegl_eglDestroyContext(const char *file, int line,
                         EGLDisplay dpy, EGLContext ctx);

EGLBoolean
__xegl_eglDestroySurface(const char *file, int line,
                         EGLDisplay dpy, EGLSurface surface);

EGLBoolean
__xegl_eglInitialize(const char *file, int line,
                     EGLDisplay dpy, EGLint *major, EGLint *minor);

EGLBoolean
__xegl_eglMakeCurrent(const char *file, int line,
		      EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);

EGLBoolean
__xegl_eglReleaseThread(const char *file, int line);

EGLBoolean
__xegl_eglSwapBuffers(const char *file, int line,
		      EGLDisplay dpy, EGLSurface surface);

EGLBoolean
__xegl_eglSwapInterval(const char *file, int line,
                       EGLDisplay dpy, EGLint interval);

EGLBoolean
__xegl_eglTerminate(const char *file, int line,
		    EGLDisplay dpy);

#define XeglGetDisplay(display_id) \
  __xegl_eglGetDisplay(__FILE__, __LINE__, display_id)

#define XeglChooseConfig(dpy, attrib_list, configs, config_size, num_config) \
  __xegl_eglChooseConfig(__FILE__, __LINE__, dpy, attrib_list, configs, config_size, num_config)

#define XeglCreateContext(dpy, config, share_context, attrib_list)	\
  __xegl_eglCreateContext(__FILE__, __LINE__, dpy, config, share_context, attrib_list)

#define XeglCreateWindowSurface(dpy, config, win, attrib_list) \
  __xegl_eglCreateWindowSurface(__FILE__, __LINE__, dpy, config, win, attrib_list)

#define XeglDestroyContext(dpy, ctx) \
  __xegl_eglDestroyContext(__FILE__, __LINE__, dpy, ctx)

#define XeglDestroySurface(dpy, surface) \
  __xegl_eglDestroySurface(__FILE__, __LINE__, dpy, surface)

#define XeglInitialize(dpy, major, minor) \
  __xegl_eglInitialize(__FILE__, __LINE__, dpy, major, minor)

#define XeglMakeCurrent(dpy, draw, read, ctx) \
  __xegl_eglMakeCurrent(__FILE__, __LINE__, dpy, draw, read, ctx)

#define XeglReleaseThread() \
  __xegl_eglReleaseThread(__FILE__, __LINE__)

#define XeglSwapBuffers(dpy, surface) \
  __xegl_eglSwapBuffers(__FILE__, __LINE__, dpy, surface)

#define XeglSwapInterval(dpy, interval)\
  __xegl_eglSwapInterval(__FILE__, __LINE__, dpy, interval)

#define XeglTerminate(dpy) \
  __xegl_eglTerminate(__FILE__, __LINE__, dpy)

#else

#define XeglGetDisplay(display_id) \
  eglGetDisplay(display_id)

#define XeglChooseConfig(dpy, attrib_list, configs, config_size, num_config) \
  eglChooseConfig(dpy, attrib_list, configs, config_size, num_config)

#define XeglCreateContext(dpy, config, share_context, attrib_list) \
  eglCreateContext(dpy, config, share_context, attrib_list)

#define XeglCreateWindowSurface(dpy, config, win, attrib_list) \
  eglCreateWindowSurface(dpy, config, win, attrib_list)

#define XeglDestroyContext(dpy, ctx) \
  eglDestroyContext(dpy, ctx)

#define XeglDestroySurface(dpy, surface) \
  eglDestroySurface(dpy, surface)

#define XeglInitialize(dpy, major, minor) \
  eglInitialize(dpy, major, minor)

#define XeglMakeCurrent(dpy, draw, read, ctx) \
  eglMakeCurrent(dpy, draw, read, ctx)

#define XeglReleaseThread() \
  eglReleaseThread()

#define XeglSwapBuffers(dpy, surface) \
  eglSwapBuffers(dpy, surface)

#define XeglSwapInterval(dpy, interval) \
  eglSwapInterval(dpy, interval)

#define XeglTerminate(dpy) \
  eglTerminate(dpy)

#endif

#endif /* EGL_HELPER_H */

/*
* Copyright (c) 2015-2016, Julien Olivain <juju@cotds.org>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* End-of-File */
