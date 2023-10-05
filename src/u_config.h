#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include "ut.h"

class ConfigWindow : public Gtk::Window {
	public :
		ConfigWindow();
		~ConfigWindow();

	protected :
		Gtk::Label infor;
		Gtk::Box binfor;
		Gtk::Entry username;
		Gtk::Entry password;
		Gtk::Button prc;
};

