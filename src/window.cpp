#include "window.h"
#include "config.h"

#define NORM " "
#define HOV ":hover "
#define AC ":active "

// init config.h
//strings str;

struct CSS {
  Glib::ustring data;
};

// if you have deleted function you can use a refrence of that function :)
void SetStyle(Gtk::Button& btn, std::string style, std::string cc, std::string base = NORM) {
  CSS cstyle;
  cstyle.data = "." + cc + base + style;
  std::cout << cstyle.data << std::endl;
  auto provider = Gtk::CssProvider::create();
  provider->load_from_data(cstyle.data);
  auto ctx = btn.get_style_context();
  ctx->add_class(cc);
  ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void SetStyle(Gtk::Box& btn, std::string style, std::string cc, std::string base = NORM) {
  CSS cstyle;
  cstyle.data = "." + cc + base + style;
  std::cout << cstyle.data << std::endl;
  auto provider = Gtk::CssProvider::create();
  provider->load_from_data(cstyle.data);
  auto ctx = btn.get_style_context();
  ctx->add_class(cc);
  ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
}


MyWindow::MyWindow() 
: m_button1(str.btn1),
  m_button2(str.btn2),
  m_button3(str.au),
  m_button4(str.gits),
  m_button5(str.git1),
  m_button6(str.git2),
  m_button7(str.git1), 
  m_button8(str.git1),
  m_button9(str.git1), 
  m_button10(str.git1),
  m_box1(Gtk::Orientation::VERTICAL),
  title(""),
  body(""),
  buttons1(Gtk::Orientation::HORIZONTAL),
  buttons2(Gtk::Orientation::HORIZONTAL)
{
	set_default_size(850, 400);
	set_title("welcome to LainOS");
	//set_child(m_box1);
	set_child(m_box1);
  title.set_justify(Gtk::Justification::CENTER);
	body.set_justify(Gtk::Justification::CENTER);
	title.set_markup("<span font='13'>Welcome to LainOS!</span>");
	body.set_markup("<span font='13'>"+ str.about +"\n\n</span>");
	m_box1.append(title);

	m_box1.append(m_area);
  m_box1.set_margin(20);
	m_box1.append(body);


	// buttons

	buttons1.append(m_button1);
  m_button1.signal_clicked().connect(
      [this]() {
          about_window = new AboutWindow();
          about_window->show();
        }
      );
	buttons1.append(m_button2);
	buttons1.append(m_button3);
	buttons1.append(m_button4);
	buttons1.append(m_button5);
	
	buttons1.set_margin(10);
	buttons2.append(m_button6);
	buttons2.append(m_button7);
	buttons2.append(m_button8);
	buttons2.append(m_button9);
	buttons2.set_valign(Gtk::Align::CENTER);
	buttons2.set_halign(Gtk::Align::CENTER);

  buttons1.set_valign(Gtk::Align::CENTER);
  buttons1.set_halign(Gtk::Align::CENTER);


	buttons2.set_margin(10);


	SetStyle(m_button1, "{margin-right: 20px;margin-left: 15px;padding-left: 60px;padding-right: 60px;}", "btn1");
	SetStyle(m_button2, "{margin-right: 20px;padding-left: 60px;padding-right: 60px;}", "btn2");
	SetStyle(m_button3, "{margin-right: 20px;padding-left: 60px;padding-right: 60px;}", "btn3");
	SetStyle(m_button4, "{margin-right: 20px;padding-left: 60px;padding-right: 60px;}", "btn4");
	SetStyle(m_button5, "{margin-right: 20px;padding-left: 60px;padding-right: 60px;}", "btn5");

	SetStyle(m_button6, "{margin-right: 25px;margin-left: 15px;padding-left: 60px;padding-right: 60px;}", "btn6");
	SetStyle(m_button7, "{margin-right: 25px;padding-left: 60px;padding-right: 60px;}", "btn7");
	SetStyle(m_button8, "{margin-right: 25px;padding-left: 60px;padding-right: 60px;}", "btn8");
	SetStyle(m_button9, "{margin-right: 25px;padding-left: 60px;padding-right: 60px;}", "btn9");

	m_box1.append(buttons2);
	m_box1.append(buttons1);


}

MyWindow::~MyWindow(){
}
