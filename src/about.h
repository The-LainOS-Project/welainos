#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include "r_image.h"


class AboutWindow : public Gtk::Window {
	public :
		AboutWindow();
		~AboutWindow();

	protected :
		Gtk::Label infor;
		Gtk::Box binfor;
		RenImage Myimage;
};

