/*
 * Copyright (C) 1997-1998 Janne L�f <jlof@mail.student.oulu.fi>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#ifndef __GTK_GL_AREA_H__
#define __GTK_GL_AREA_H__

#include <gdk/gdk.h>
#include <gtkgl/gdkgl.h>
#include <gtk/gtkwidget.h>


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define GTK_GL_AREA(obj)          GTK_CHECK_CAST (obj, gtk_gl_area_get_type (), GtkGLArea)
#define GTK_GL_AREA_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass, gtk_gl_area_get_type (), GtkGLAreaClass)
#define GTK_IS_GL_AREA(obj)       GTK_CHECK_TYPE (obj, gtk_gl_area_get_type ())


typedef struct _GtkGLArea       GtkGLArea;
typedef struct _GtkGLAreaClass  GtkGLAreaClass;


struct _GtkGLArea
{
  GtkWidget    widget;
  GdkGLContext *glcontext;
};

struct _GtkGLAreaClass
{
  GtkWidgetClass parent_class;
};

guint      gtk_gl_area_get_type   (void);

GtkWidget* gtk_gl_area_new        (int       *attrList);
GtkWidget* gtk_gl_area_share_new  (int       *attrList,
                                   GtkGLArea *share);
GtkWidget* gtk_gl_area_new_vargs  (GtkGLArea *share,
				   ...);

gint       gtk_gl_area_begingl    (GtkGLArea *glarea);
void       gtk_gl_area_endgl      (GtkGLArea *glarea);
void       gtk_gl_area_swapbuffers(GtkGLArea *glarea);

void       gtk_gl_area_size       (GtkGLArea *glarea,
				   gint width,
				   gint height);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __GTK_GL_AREA_H__ */
