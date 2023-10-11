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
		Gtk::Box binfor;
		Gtk::Box page1, page2, page3;
		Gtk::Box page2_option1;
		Gtk::Notebook m_Notebook;
		Gtk::Label c_label, combo_label;
		Gtk::Entry username;
		Gtk::Entry password;
		Gtk::Button submit_btn;
		RenImage mygif;
		Gtk::Grid options;
		Gtk::ComboBoxText m_Combo;
};

