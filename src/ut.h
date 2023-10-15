#include <gtkmm.h>
#include <iostream>
#include "about.h"

#define NORM " "
#define HOV ":hover "
#define AC ":active "

typedef Gtk::Box ImageButton;

class Tools {
public: 
    // if you have deleted function you can use a refrence of that function :)
  static void SetStyle(Gtk::Button& btn, std::string style, std::string cc, std::string base = NORM) {
    CSS cstyle;
    cstyle.data = "." + cc + base + style;
    std::cout << cstyle.data << std::endl;
    auto provider = Gtk::CssProvider::create();
    provider->load_from_data(cstyle.data);
    auto ctx = btn.get_style_context();
    ctx->add_class(cc);
    ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  }

  static void SetStyle(Gtk::Box& btn, std::string style, std::string cc, std::string base = NORM) {
    CSS cstyle;
    cstyle.data = "." + cc + base + style;
    std::cout << cstyle.data << std::endl;
    auto provider = Gtk::CssProvider::create();
    provider->load_from_data(cstyle.data);
    auto ctx = btn.get_style_context();
    ctx->add_class(cc);
    ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  }
    static void SetStyle(Gtk::Entry& btn, std::string style, std::string cc, std::string base = NORM) {
    CSS cstyle;
    cstyle.data = "." + cc + base + style;
    std::cout << cstyle.data << std::endl;
    auto provider = Gtk::CssProvider::create();
    provider->load_from_data(cstyle.data);
    auto ctx = btn.get_style_context();
    ctx->add_class(cc);
    ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  }
  static void SetStyle(Gtk::Image& btn, std::string style, std::string cc, std::string base = NORM) {
    CSS cstyle;
    cstyle.data = "." + cc + base + style;
    std::cout << cstyle.data << std::endl;
    auto provider = Gtk::CssProvider::create();
    provider->load_from_data(cstyle.data);
    auto ctx = btn.get_style_context();
    ctx->add_class(cc);
    ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  }
  static void SetStyle(Gtk::Grid& btn, std::string style, std::string cc, std::string base = NORM) {
    CSS cstyle;
    cstyle.data = "." + cc + base + style;
    std::cout << cstyle.data << std::endl;
    auto provider = Gtk::CssProvider::create();
    provider->load_from_data(cstyle.data);
    auto ctx = btn.get_style_context();
    ctx->add_class(cc);
    ctx->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_USER);
  }
  template <class T> 
  static void OpenWindow() {
    Gtk::Window *sample_window = new T();
    sample_window->show();
  }
  static void UpgradeOption() {
    // do the upgrade code here ...
    system("xfce4-terminal -e 'bash -c \"sudo pacman -Syu && read\"' &");
  }
  static void OpenLink(std::string link) {
    std::string cmd = "firefox " + link + " &";
    system(cmd.c_str());
  }
  static Gtk::Box *CreateImageButton(std::string image_path, std::string style) {
    RenImage *ImageSample = new RenImage(image_path, 30, 30);
    auto hboxr = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
    hboxr->set_valign(Gtk::Align::CENTER);
    hboxr->set_halign(Gtk::Align::CENTER);
    hboxr->append(*ImageSample);
    return hboxr;
  }
  // static void OpenAboutWindow(Gtk::Window *sample) {
  //   Gtk::Window *about_window = new ()*sample();
  //   about_window->show();
  // }
protected:
  struct CSS {
    Glib::ustring data;
  };

};