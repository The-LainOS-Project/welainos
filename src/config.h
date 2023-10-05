#include <string>

struct strings {
	std::string title = "Welcome to LainOS!";
	std::string btn1 = "readme";
	std::string btn2 = "website/weblog";
	std::string au = "Authers";
	std::string gits = "gits";
	std::string git1 = "Github";
	std::string git2 = "Gitlab";
	std::string config_title = "Welcome To Config Section!\n \
In this option, you can set your username and password for your lainOS.\n \
but, notice that your default username and password is *lainos*. \n \
if you wanna change that, you can fill these inputs and click config. \n";
	std::string about = "LainOS Layer 1 - arch linux version\n \
If you wanna support us, please visit our website, or choose one of these buttons";
};

// Init config
static strings str;
