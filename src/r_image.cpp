#include "r_image.h"
#include <cairomm/context.h>
#include <giomm/resource.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glibmm/fileutils.h>
#include <iostream>

RenImage::RenImage(std::string Ipath, int w, int h)
{
  m_image = Gdk::Pixbuf::create_from_file(Ipath);
  set_content_width(w);
  set_content_height(h);
  m_image = m_image->scale_simple(w, h, Gdk::InterpType::BILINEAR);
  set_draw_func(sigc::mem_fun(*this, &RenImage::on_draw));
}

RenImage::~RenImage()
{
}

Glib::RefPtr<Gdk::Pixbuf> RenImage::resizeImage(Glib::RefPtr<Gdk::Pixbuf> pixbuf, Gdk::Rectangle rectangle) {

  // int width, height;
  // double zoom_raito;
  // double widget_raito = (double)rectangle.get_width() / (double)rectangle.get_height();
  // double image_raito = (double)pixbuf->get_width() / (double)pixbuf->get_height();

  // //calculating desired width and height
  // if(widget_raito >= image_raito) {
  //   height = rectangle.get_height() - 4;
  //   width = height * image_raito;
  //   zoom_raito = (double)rectangle.get_height() / (double)pixbuf->get_height();
  // } else {
  //   width = rectangle.get_width() - 4;
  //   height = width / image_raito;
  //   zoom_raito = (double)rectangle.get_width() / (double)pixbuf->get_width();
  // }

  // //zoom widget adjusting
  // window->zoom_slider.set_range(zoom_raito * 100.0, 400.0);
  // window->zoom_slider.set_value(zoom_raito * 100.0);

  // //image resizing
  // return pixbuf->scale_simple(width, height, Gdk::INTERP_BILINEAR);
}

void RenImage::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
  if (!m_image)
    return;

  // // Draw the image in the middle of the drawing area, or (if the image is
  // // larger than the drawing area) draw the middle part of the image.
  // Gdk::Cairo::set_source_pixbuf(cr, m_image,
  //   (width - m_image->get_width())/2, (height - m_image->get_height())/2);
  // cr->paint();

  Gdk::Cairo::set_source_pixbuf(cr, m_image, (width - m_image->get_width())/2, (height - m_image->get_height())/2);
  // //cr->rectangle(50, 50, m_image->get_width()-20, m_image->get_height()-20);
  // //cr->fill();
  cr->paint();

//   auto style_context = get_style_context();
// style_context->render_background(cr, 0, 0, width, height);
// cr->arc(width / 2.0, height / 2.0, std::min(width, height) / 2.0, 0, 2* M_PI);
// auto color = style_context->get_color();
// Gdk::Cairo::set_source_pixbuf(cr, m_image, (width - m_image->get_width())/2, (height - m_image->get_height())/2);
// cr->fill();
}
