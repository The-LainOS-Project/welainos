//#ifndef R_IMAGE_H
//#define R_IMAGE_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class RenImage: public Gtk::DrawingArea
{
public:
  RenImage(std::string Ipath, int w, int h);
  virtual ~RenImage();
protected:
  void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
  Glib::RefPtr<Gdk::Pixbuf> resizeImage(Glib::RefPtr<Gdk::Pixbuf> pixbuf, Gdk::Rectangle rectangle);


  Glib::RefPtr<Gdk::Pixbuf> m_image;
};

//#endif
