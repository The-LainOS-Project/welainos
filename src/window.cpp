#include "window.h"
#include "config.h"

// // if you have deleted function you can use a refrence of that function :)
// void SetStyle(Gtk::Button& btn, std::string style, std::string cc, std::string base = NORM) {
//   CSS cstyle;
//   cstyle.data = "." + cc + base + style;
//   std::cout << cstyle.data << std::endl;
//   auto provider = Gtk::CssProvider::create();
//   provider->load_from_data(cstyle.data);
//   auto ctx = btn.get_style_context();
//   ctx->add_class(cc);
//   ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
// }

// void SetStyle(Gtk::Box& btn, std::string style, std::string cc, std::string base = NORM) {
//   CSS cstyle;
//   cstyle.data = "." + cc + base + style;
//   std::cout << cstyle.data << std::endl;
//   auto provider = Gtk::CssProvider::create();
//   provider->load_from_data(cstyle.data);
//   auto ctx = btn.get_style_context();
//   ctx->add_class(cc);
//   ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
// }


MyWindow::MyWindow() 
: m_button1(str.btn1),
  m_button2(str.btn2),
  m_button3(str.au),
  m_button4(str.github),
  m_button5("test"),
  m_button6("test"),
  m_button7("test"), 
  m_button8("test"),
  m_button9("test"), 
  m_button10("test"),
  m_area("/usr/share/icons/a.svg", 60, 60),
  s_area("/usr/share/icons/b.png", 30, 30),
  c_area("/usr/share/icons/c.png", 30, 30),
  d_area("/usr/share/icons/d.png", 30, 30),
  org(),
  reddit(),
  youtube(),
  blog(),
  reddit2(),
  youtube2(),
  blog2(),
  myimage("/usr/share/icons/a.svg"),
  m_box1(Gtk::Orientation::VERTICAL),
  title(""),
  body(""),
  l1("Gits"),
  l2("Settings"),
  l3("informations"),
  buttons1(Gtk::Orientation::HORIZONTAL),
  buttons2(Gtk::Orientation::HORIZONTAL),
  buttons3(Gtk::Orientation::HORIZONTAL),
  button_frame(Gtk::Orientation::HORIZONTAL),
  button_frame2(Gtk::Orientation::HORIZONTAL)
{
	set_default_size(850, 400);
	set_title("welcome to LainOS");
	//set_child(m_box1);
	set_child(m_box1);
  title.set_justify(Gtk::Justification::CENTER);
	body.set_justify(Gtk::Justification::CENTER);
	title.set_markup("<span font='15'>Welcome to LainOS!</span>");
	body.set_markup("<span font='12' font-family='ani'>\n"+ str.about +"\n</span>");
	m_box1.append(m_area);
	m_box1.append(title);
	m_box1.append(body);
	buttons1.set_valign(Gtk::Align::CENTER);
	buttons1.set_halign(Gtk::Align::CENTER);

	buttons2.set_valign(Gtk::Align::CENTER);
	buttons2.set_halign(Gtk::Align::CENTER);
	org.set_row_homogeneous(true);
	org.set_column_homogeneous(true);
	org.set_column_spacing(20);
	org.set_row_spacing(20);
 	int btn_h = 2;
 	int btn_w = 4;
 	org.attach(l1, 0,       	1, 	  			btn_h, btn_w);
	org.attach(l2, btn_h*2, 	1, 				btn_h, btn_w);
	org.attach(l3, btn_h*4, 	1, 				btn_h, btn_w);

	org.attach(m_button1, 0,       	4, 	  			btn_h, btn_w);
	org.attach(m_button2, btn_h*2, 	4, 				btn_h, btn_w);
	org.attach(m_button3, btn_h*4, 	4, 				btn_h, btn_w);

	org.attach(m_button4, 0, 		btn_w*4, 	  	btn_h, btn_w);
	org.attach(m_button5, btn_h*2, 	btn_w*4, 		btn_h, btn_w);
	org.attach(m_button6, btn_h*4, 	btn_w*4, 		btn_h, btn_w);

	org.attach(m_button7, 0, 		btn_w*8, 	  	btn_h, btn_w);
	org.attach(m_button8, btn_h*2, 	btn_w*8, 		btn_h, btn_w);
	org.attach(m_button9, btn_h*4, 	btn_w*8, 		btn_h, btn_w);

	m_button1.signal_clicked().connect(sigc::ptr_fun(&Tools::OpenWindow<AboutWindow>));
	m_button2.signal_clicked().connect(sigc::bind(sigc::ptr_fun(&Tools::OpenLink),	std::string("https://lainos.org")));
	m_button3.signal_clicked().connect(sigc::bind(sigc::ptr_fun(&Tools::OpenLink),	std::string("https://lainos.org")));
	m_button4.signal_clicked().connect(sigc::bind(sigc::ptr_fun(Tools::OpenLink), 	std::string("https://github.com/The-LainOS-Project")));
	m_button5.signal_clicked().connect(sigc::ptr_fun(&Tools::OpenWindow<ConfigWindow>));

	org.set_margin(10);

	buttons1.append(org);

    auto hboxr = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
    hboxr->set_valign(Gtk::Align::CENTER);
    hboxr->set_halign(Gtk::Align::CENTER);
    hboxr->append(s_area);
    reddit.set_child(*hboxr);

    auto hboxr2 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
    hboxr2->set_valign(Gtk::Align::CENTER);
    hboxr2->set_halign(Gtk::Align::CENTER);
    hboxr2->append(c_area);
    youtube.set_child(*hboxr2);

    auto hboxr3 = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
    hboxr3->set_valign(Gtk::Align::CENTER);
    hboxr3->set_halign(Gtk::Align::CENTER);
    hboxr3->append(d_area);
    blog.set_child(*hboxr3);

    reddit.signal_clicked().connect(
    	[this](){
    		system("chromium https://reddit.com/r/lainosdevelopers &");
    	}
    );

	buttons2.append(reddit);
	buttons2.append(youtube);
	buttons2.append(blog);

	buttons2.set_margin(10);

	m_box1.append(buttons1);
	m_box1.append(buttons2);

//   m_box1.set_margin(20);
// 	m_box1.append(body);
//  	Gtk::Box *result = Tools::CreateImageButton("/usr/share/icons/a.svg", "reddit", "{color: green;}");
//   	Gtk::Box *result2 = Tools::CreateImageButton("/usr/share/icons/a.svg", "youtube", "{color: green;}");
//   	Gtk::Box *result3 = Tools::CreateImageButton("/usr/share/icons/a.svg", "blog", "{color: green;}");
//   	reddit.set_child(*result);
//   	youtube.set_child(*result2);
//   	blog.set_child(*result3);

//   	Gtk::Box *result4 = Tools::CreateImageButton("/usr/share/icons/a.svg", "reddit", "{color: green;}");
//   	Gtk::Box *result5 = Tools::CreateImageButton("/usr/share/icons/a.svg", "youtube", "{color: green;}");
//   	Gtk::Box *result6 = Tools::CreateImageButton("/usr/share/icons/a.svg", "blog", "{color: green;}");
//   	reddit2.set_child(*result4);
//   	youtube2.set_child(*result5);
//   	blog2.set_child(*result6);

//   	// this is not the best way of doing this, I will change these later
//   	Tools::SetStyle(reddit, "{margin-left: 410px;}", "reddit_btn");
//   	Tools::SetStyle(youtube, "{margin-right: 10px; margin-left: 10px;}", "youtube_btn");
//   	Tools::SetStyle(blog, "{margin-right: 410px;}", "blog_btn");
//   	// Tools::SetStyle(blog2, "{}", "blog_btn");
//   	Tools::SetStyle(buttons3, "{margin-top: 10px;}", "button3_btns");

//   	buttons3.append(reddit);
//   	buttons3.append(youtube);
//   	buttons3.append(blog);
//   	// buttons3.append(blog2);
// // 

// 	// buttons

// 	// buttons1.append(m_button1);
// 	m_button1.signal_clicked().connect(sigc::ptr_fun(&Tools::OpenWindow<AboutWindow>));
//   // m_button1.signal_clicked().connect(
//   //     [this]() {
//   //         about_window = new AboutWindow();
//   //         about_window->show();
//   //       }
//   //     );
// 	buttons1.append(m_button2);
//   	m_button2.signal_clicked().connect(sigc::ptr_fun(&Tools::OpenWindow<ConfigWindow>));
// 	buttons1.append(m_button3);
//   	m_button3.signal_clicked().connect(sigc::ptr_fun(&Tools::UpgradeOption));
// 	buttons1.append(m_button4);
//   	// m_button4.signal_clicked().connect(sigc::ptr_fun(&Tools::OpenWindow<AboutWindow>));
// 	// buttons1.append(m_button5);
	
// 	buttons1.set_margin(10);
// 	// buttons2.append(m_button6);
// 	buttons2.append(m_button7);
// 	buttons2.append(m_button8);
// 	buttons2.append(m_button9);
// 	buttons2.set_valign(Gtk::Align::CENTER);
// 	buttons2.set_halign(Gtk::Align::CENTER);

//   buttons1.set_valign(Gtk::Align::CENTER);
//   buttons1.set_halign(Gtk::Align::CENTER);


// 	buttons2.set_margin(10);

// 	// auto pmap = Gtk::make_managed<Gtk::Image>("/usr/share/icons/a.svg");
//  //  	auto label = Gtk::make_managed<Gtk::Label>("cool button");
//  //  	label->set_expand(true);

  	

//  //  	//Put them in a Box:
//  //  	auto hboxr = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
//  //  	hboxr->append(*pmap);
//  //  	hboxr->append(*label)

// 	// Gtk::Allocation image_setting;
// 	// image_setting.set_width(1000);
// 	// image_setting.set_height(1000);
// 	// buttons2.size_allocate(image_setting, myimage.get_allocated_baseline());
// 	// buttons2.append(myimage);
//   	//And put that Box in the button:



	Tools::SetStyle(m_button1, "{border:0;background:whitesmoke;}", "btn1");
	Tools::SetStyle(m_button1, "{color:gray;}", "btn1", AC);
	Tools::SetStyle(m_button1, "{background:white;box-shadow: 1px 1px 5px gray;}", "btn1", HOV);
	Tools::SetStyle(m_button2, "{border:0;background:whitesmoke;}", "btn2");
	Tools::SetStyle(m_button2, "{color:gray;}", "btn2", AC);
	Tools::SetStyle(m_button2, "{background:white;}", "btn2", HOV);
	Tools::SetStyle(m_button3, "{border:0;background:whitesmoke;}", "btn3");
	Tools::SetStyle(m_button3, "{color:gray;}", "btn3", AC);
	Tools::SetStyle(m_button3, "{background:white;}", "btn3", HOV);
	Tools::SetStyle(m_button4, "{border:0;background:whitesmoke;}", "btn4");
	Tools::SetStyle(m_button4, "{color:gray;}", "btn4", AC);
	Tools::SetStyle(m_button4, "{background:white;}", "btn4", HOV);
	Tools::SetStyle(m_button5, "{border:0;background:whitesmoke;}", "btn5");
	Tools::SetStyle(m_button5, "{color:gray;}", "btn5", AC);
	Tools::SetStyle(m_button5, "{background:white;}", "btn5", HOV);

	Tools::SetStyle(m_button6, "{border:0;background:whitesmoke;}", "btn6");
	Tools::SetStyle(m_button6, "{color:gray;}", "btn6", AC);
	Tools::SetStyle(m_button6, "{background:white;}", "btn6", HOV);
	Tools::SetStyle(m_button7, "{border:0;background:whitesmoke;}", "btn7");
	Tools::SetStyle(m_button7, "{color:gray;}", "btn7", AC);
	Tools::SetStyle(m_button7, "{background:white;}", "btn7", HOV);
	Tools::SetStyle(m_button8, "{border:0;background:whitesmoke;}", "btn8");
	Tools::SetStyle(m_button8, "{color:gray;}", "btn8", AC);
	Tools::SetStyle(m_button8, "{background:white;}", "btn8", HOV);
	Tools::SetStyle(m_button9, "{border:0;background:whitesmoke;}", "btn9");
	Tools::SetStyle(m_button9, "{color:gray;}", "btn9", AC);
	Tools::SetStyle(m_button9, "{background:white;}", "btn9", HOV);


	Tools::SetStyle(reddit, "{border:0;background:whitesmoke;}", "reddit_btn");
	Tools::SetStyle(youtube, "{border:0;background:whitesmoke;}", "youtube_btn");
	Tools::SetStyle(blog, "{border:0;background:whitesmoke;}", "blog_btn");


// 	m_box1.append(buttons2);
// 	m_box1.append(buttons1);
	// m_box1.append(buttons3);

}

MyWindow::~MyWindow(){
}
