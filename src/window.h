#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <iostream>
#include "about.h"
#include "u_config.h"


class MyWindow : public Gtk::Window {
	public :
		MyWindow();
		~MyWindow() override;

	protected :
		Gtk::Box m_box1;
		Gtk::Box buttons1;
		Gtk::Box buttons2;
		Gtk::Box buttons3;
		Gtk::Box button_frame;
		Gtk::Box button_frame2;
		Gtk::Grid org;
		Gtk::Button m_button1, m_button2, m_button3, m_button4,
			m_button5, m_button6, m_button7, m_button8, m_button9, m_button10;
		Gtk::Button reddit, youtube, blog;
		Gtk::Button reddit2, youtube2, blog2;
		Gtk::Image myimage;
		Gtk::Label title;
		Gtk::Label body;
		Gtk::Label l1, l2, l3;
		RenImage m_area;
		RenImage s_area;
		RenImage c_area;
		RenImage d_area;
    Gtk::Window *about_window;
    Gtk::Window *config_window;
    
};

