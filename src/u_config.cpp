#include "u_config.h"
#include "config.h"
// #include "r_image.h"


ConfigWindow::ConfigWindow()
: binfor(Gtk::Orientation::VERTICAL),
page1(Gtk::Orientation::VERTICAL),
page2_option1(Gtk::Orientation::HORIZONTAL),
page2(Gtk::Orientation::VERTICAL),
page3(Gtk::Orientation::VERTICAL),
c_label(str.user_config_up),
username(),
password(),
submit_btn("Config"),
combo_label("Default theme"),
mygif("../new.gif", 50, 50)
{
	set_default_size(600, 400);
	set_title("About page");
	set_child(binfor);
	c_label.set_justify(Gtk::Justification::CENTER);
	m_Notebook.set_expand();
	m_Notebook.append_page(page1, "login");
	m_Notebook.append_page(page2, "shell");
	m_Notebook.append_page(page3, "theme");

	page1.set_margin(20);
	c_label.set_margin(5);
	username.set_margin(5);
	password.set_margin(5);
	submit_btn.set_margin(5);
	page1.append(c_label);
	page1.append(username);
	page1.append(password);
	page1.append(submit_btn);
	page1.append(mygif);

	page2.set_margin(20);

	options.set_row_homogeneous(true);
	options.set_column_homogeneous(true);
	options.set_column_spacing(20);
	options.set_row_spacing(20);
	// combo_label.set_justify(Gtk::Justification::LEFT);
	options.attach(combo_label, 0,       	1, 	  			2, 2);
	options.attach(m_Combo, 2,       	1, 	  			 2, 2);

	// options.set_margin(20);


	// combo_label.set_valign(Gtk::Align::START);
	// combo_label.set_halign(Gtk::Align::START);
    // page2_option1.set_halign(Gtk::Align::CENTER);
/*	page2_option1.append(combo_label);
	combo_label.set_margin(10);
	combo_label.set_expand();*/
	m_Combo.append("White");
	m_Combo.append("Dark");
	m_Combo.append("LainOS");

	page2.append(options);
	// page2_option1.append(m_Combo);

	page2.append(page2_option1);

	binfor.append(m_Notebook);


}

ConfigWindow::~ConfigWindow() 
{

}