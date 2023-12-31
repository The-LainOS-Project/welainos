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
field1(),
submit_btn2("submit"),
submit_btn("Config"),
l_field1("Text Field 1"),
l_field2("Text Field 2"),
combo_label("Default theme")
// mygif("../new.gif", 50, 50)
{
	set_default_size(600, 400);
	set_title("About page");
	set_child(binfor);
	c_label.set_justify(Gtk::Justification::CENTER);
	l_field1.set_justify(Gtk::Justification::CENTER);
	l_field2.set_justify(Gtk::Justification::CENTER);
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
	// page1.append(mygif);

	page2.set_margin(15);

	options.set_row_homogeneous(true);
	options.set_column_homogeneous(true);
	options.set_column_spacing(20);
	options.set_row_spacing(20);

	combo_label.set_valign(Gtk::Align::CENTER);
	combo_label.set_halign(Gtk::Align::START);
	l_field1.set_valign(Gtk::Align::CENTER);
	l_field1.set_halign(Gtk::Align::START);
	l_field2.set_valign(Gtk::Align::CENTER);
	l_field2.set_halign(Gtk::Align::START);

	// combo_label.set_justify(Gtk::Justification::LEFT);
	options.attach(combo_label, 0,      1, 	  			 2, 2);
	options.attach(m_Combo,     2,      1, 	  			 2, 2);

	options.attach(l_field1,    0,       4, 	  		 2, 2);
	options.attach(field1,      2,       4, 	  		 2, 2);

	options.attach(l_field2,      0,       8, 	  		 2, 2);
	options.attach(m_Combo2,      2,       8, 	  		 2, 2);



	// options.set_margin(20);



    // page2_option1.set_halign(Gtk::Align::CENTER);
/*	page2_option1.append(combo_label);
	combo_label.set_margin(10);
	combo_label.set_expand();*/
	m_Combo.append("White");
	m_Combo.append("Dark");
	m_Combo.append("LainOS");

	m_Combo2.append("White");
	m_Combo2.append("Dark");
	m_Combo2.append("LainOS");
	m_Combo2.append("LainOS");
	m_Combo2.append("LainOS");
	m_Combo2.append("LainOS");
	m_Combo2.append("LainOS");
	m_Combo2.append("LainOS");

	page2.append(options);
	// page2_option1.append(m_Combo);

	page2.append(page2_option1);
	submit_btn2.set_margin_top(20);
	Tools::SetStyle(submit_btn2, "{padding: 5px;}", "submit_btn2");
	submit_btn2.set_valign(Gtk::Align::END);
	submit_btn2.set_halign(Gtk::Align::FILL);
	page2.append(submit_btn2);
	binfor.append(m_Notebook);


}

ConfigWindow::~ConfigWindow() 
{

}