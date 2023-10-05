#include "u_config.h"
#include "config.h"


ConfigWindow::ConfigWindow()
: binfor(Gtk::Orientation::VERTICAL),
  infor(""),
  username(),
  password(),
  prc("Config")
{
	set_default_size(600, 400);
	set_title("About page");
	set_child(binfor);
	infor.set_justify(Gtk::Justification::CENTER);
	infor.set_markup("<span font='10' font-family='adler'>"+str.config_title+"</span>");
	binfor.set_valign(Gtk::Align::CENTER);
	binfor.set_halign(Gtk::Align::CENTER);
	binfor.append(infor);
	binfor.append(username);
	binfor.append(password);
	binfor.append(prc);
	username.set_margin(20);
	password.set_margin(20);
	prc.set_margin(20);
	Tools::SetStyle(username, "{margin-left: 40px;margin-right:40px;}", "username_style");
	Tools::SetStyle(password, "{margin-left: 40px;margin-right:40px;}", "password_style");
	Tools::SetStyle(prc, "{color: green;margin-left: 40px;margin-right:40px;}", "button_prc");
}

ConfigWindow::~ConfigWindow() 
{

}