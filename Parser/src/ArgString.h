//this library takes care of getting arguments as strings

#include <string>
#include <vector>

class ArgString {
	std::vector<std::string> args;

	public:
		ArgString(int size, char** array){
			for(int i = 0; i < size; i++){
				args.push_back(std::string(array[i]));
			}
		}

		std::vector<std::string> get(){
			return args;
		}
};
