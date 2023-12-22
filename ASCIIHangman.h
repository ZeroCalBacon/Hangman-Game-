#include <iostream>
#include <string>

using namespace std;


class ASCIIHangman {
    public:
    static string ASCIIHangmanNone() {
        return R"(








                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||                                          _________  ________  ___  _______   ________          
                                            | | /        ||                                         |\___   ___\\   __  \|\  \|\  ___ \ |\   ____\  ___    
                                            | |/         ||                                         \|___ \  \_\ \  \|\  \ \  \ \   __/|\ \  \___|_|\__\   
                                            | |          ||                                              \ \  \ \ \   _  _\ \  \ \  \_|/_\ \_____  \|__|   
                                            | |          (\\_                                             \ \  \ \ \  \\  \\ \  \ \  \_|\ \|____|\  \  ___ 
                                            | |           `--'                                             \ \__\ \ \__\\ _\\ \__\ \_______\____\_\  \|\__\
                                            | |                                                             \|__|  \|__|\|__|\|__|\|_______|\_________\|__|
                                            | |                                                                          ________           \|_________|    
                                            | |                                                                         |\   ____\                          
                                            | |                                                                         \ \  \___|                          
                                            | |                                                                          \ \  \____                         
                                            | |                                                                           \ \  ___  \                       
                                            | |                                                                            \ \_______\                      
                                            | |                                                                             \|_______|                      
                                            | |
                                            """"""""""|_        |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }

    static string ASCIIHangmanHead() {
        return R"(








                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||                                          _________  ________  ___  _______   ________          
                                            | | /        ||.-''.                                    |\___   ___\\   __  \|\  \|\  ___ \ |\   ____\  ___    
                                            | |/         |/  _  \                                   \|___ \  \_\ \  \|\  \ \  \ \   __/|\ \  \___|_|\__\   
                                            | |          ||  `/,|                                        \ \  \ \ \   _  _\ \  \ \  \_|/_\ \_____  \|__|   
                                            | |          (\\`_.'                                          \ \  \ \ \  \\  \\ \  \ \  \_|\ \|____|\  \  ___ 
                                            | |           `--'                                             \ \__\ \ \__\\ _\\ \__\ \_______\____\_\  \|\__\
                                            | |                                                             \|__|  \|__|\|__|\|__|\|_______|\_________\|__|
                                            | |                                                                          ________           \|_________|    
                                            | |                                                                         |\   ____\                          
                                            | |                                                                         \ \  \___|_                         
                                            | |                                                                          \ \_____  \                        
                                            | |                                                                           \|____|\  \                       
                                            | |                                                                             ____\_\  \                      
                                            | |                                                                            |\_________\                     
                                            | |                                                                            \|_________|                     
                                            """"""""""|_        |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }

    static string ASCIIHangmanBody() {
        return R"(








                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||                                          _________  ________  ___  _______   ________          
                                            | | /        ||.-''.                                    |\___   ___\\   __  \|\  \|\  ___ \ |\   ____\  ___    
                                            | |/         |/  _  \                                   \|___ \  \_\ \  \|\  \ \  \ \   __/|\ \  \___|_|\__\   
                                            | |          ||  `/,|                                        \ \  \ \ \   _  _\ \  \ \  \_|/_\ \_____  \|__|   
                                            | |          (\\`_.'                                          \ \  \ \ \  \\  \\ \  \ \  \_|\ \|____|\  \  ___ 
                                            | |         .-`--'.                                            \ \__\ \ \__\\ _\\ \__\ \_______\____\_\  \|\__\
                                            | |         \     /                                             \|__|  \|__|\|__|\|__|\|_______|\_________\|__|
                                            | |          |   |                                                           ___   ___          \|_________|    
                                            | |          |   |                                                          |\  \ |\  \                         
                                            | |          |   |                                                          \ \  \\_\  \                        
                                            | |          `- -'                                                           \ \______  \                       
                                            | |                                                                           \|_____|\  \                      
                                            | |                                                                                  \ \__\                     
                                            | |                                                                                   \|__|                    
                                            | |         
                                            """"""""""|_        |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }

    static string ASCIIHangmanArmL() {
        return R"(








                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||                                          _________  ________  ___  _______   ________            
                                            | | /        ||.-''.                                    |\___   ___\\   __  \|\  \|\  ___ \ |\   ____\  ___    
                                            | |/         |/  _  \                                   \|___ \  \_\ \  \|\  \ \  \ \   __/|\ \  \___|_|\__\   
                                            | |          ||  `/,|                                        \ \  \ \ \   _  _\ \  \ \  \_|/_\ \_____  \|__|   
                                            | |          (\\`_.'                                          \ \  \ \ \  \\  \\ \  \ \  \_|\ \|____|\  \  ___ 
                                            | |         .-`--'.                                            \ \__\ \ \__\\ _\\ \__\ \_______\____\_\  \|\__\
                                            | |        /Y     /                                             \|__|  \|__|\|__|\|__|\|_______|\_________\|__|
                                            | |       // |   |                                                          ________           \|_________|    
                                            | |      //  |   |                                                         |\_____  \                          
                                            | |     ')   |   |                                                         \|____|\ /_                         
                                            | |          `- -'                                                               \|\  \                        
                                            | |                                                                             __\_\  \                       
                                            | |                                                                            |\_______\                      
                                            | |                                                                             \|_______|                      
                                            | |                 
                                            """"""""""|_        |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }

    static string ASCIIHangmanArmR() {
        return R"(








                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||                                          _________  ________  ___  _______   ________          
                                            | | /        ||.-''.                                    |\___   ___\\   __  \|\  \|\  ___ \ |\   ____\  ___    
                                            | |/         |/  _  \                                   \|___ \  \_\ \  \|\  \ \  \ \   __/|\ \  \___|_|\__\   
                                            | |          ||  `/,|                                        \ \  \ \ \   _  _\ \  \ \  \_|/_\ \_____  \|__|   
                                            | |          (\\`_.'                                          \ \  \ \ \  \\  \\ \  \ \  \_|\ \|____|\  \  ___ 
                                            | |         .-`--'.                                            \ \__\ \ \__\\ _\\ \__\ \_______\____\_\  \|\__\
                                            | |        /Y     Y\                                            \|__|  \|__|\|__|\|__|\|_______|\_________\|__|
                                            | |       // |   | \\                                                        _______           \|_________|    
                                            | |      //  |   |  \\                                                      /  ___  \                          
                                            | |     ')   |   |   (`                                                    /__/|_/  /|                         
                                            | |          `- -'                                                         |__|//  / /                         
                                            | |                                                                            /  /_/__                        
                                            | |                                                                           |\________\                      
                                            | |                                                                            \|_______|                      
                                            | |         
                                            """"""""""|_        |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }

    static string ASCIIHangmanLegL() {
        return R"(








                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||                                          _________  ________  ___  _______   ________          
                                            | | /        ||.-''.                                    |\___   ___\\   __  \|\  \|\  ___ \ |\   ____\  ___    
                                            | |/         |/  _  \                                   \|___ \  \_\ \  \|\  \ \  \ \   __/|\ \  \___|_|\__\   
                                            | |          ||  `/,|                                        \ \  \ \ \   _  _\ \  \ \  \_|/_\ \_____  \|__|   
                                            | |          (\\`_.'                                          \ \  \ \ \  \\  \\ \  \ \  \_|\ \|____|\  \  ___ 
                                            | |         .-`--'.                                            \ \__\ \ \__\\ _\\ \__\ \_______\____\_\  \|\__\
                                            | |        /Y     Y\                                            \|__|  \|__|\|__|\|__|\|_______|\_________\|__|
                                            | |       // |   | \\                                                         _____             \|_________|    
                                            | |      //  |   |  \\                                                       / __  \                            
                                            | |     ')   |   |   (`                                                     |\/_|\  \                           
                                            | |          || -'                                                          \|/ \ \  \                          
                                            | |          ||                                                                  \ \  \                         
                                            | |          ||                                                                   \ \__\                        
                                            | |          ||                                                                    \|__|                        
                                            | |         / |
                                            """"""""""|_`-'     |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }

    static string ASCIIHangmanFull() {
        return R"(







            
                                             ___________.._______
                                            | .__________))______|
                                            | | / /      ||
                                            | |/ /       ||
                                            | | /        ||.-''.
                                            | |/         |/  _  \
                                            | |          ||  `/,|                                  ___  ___  ________  ________   ________  _______   ________  ___
                                            | |          (\\`_.'                                  |\  \|\  \|\   __  \|\   ___  \|\   ____\|\  ___ \ |\   ___ \|\  \      
                                            | |         .-`--'.                                   \ \  \\\  \ \  \|\  \ \  \\ \  \ \  \___|\ \   __/|\ \  \_|\ \ \  \     
                                            | |        /Y     Y\                                   \ \   __  \ \   __  \ \  \\ \  \ \  \  __\ \  \_|/_\ \  \ \\ \ \  \    
                                            | |       // |   | \\                                   \ \  \ \  \ \  \ \  \ \  \\ \  \ \  \|\  \ \  \_|\ \ \  \_\\ \ \__\   
                                            | |      //  |   |  \\                                   \ \__\ \__\ \__\ \__\ \__\\ \__\ \_______\ \_______\ \_______\|__|   
                                            | |     ')   |   |   (`                                   \|__|\|__|\|__|\|__|\|__| \|__|\|_______|\|_______|\|_______|   ___ 
                                            | |          || ||                                                                                                       |\__\
                                            | |          || ||                                                                                                       \|__|
                                            | |          || ||            
                                            | |          || ||
                                            | |         / | | \
                                            """"""""""|_`-' `-' |"""|
                                            |"|"""""""\ \       '"|"|
                                            | |        \ \        | |
                                            : :         \ \       : :
                                            ...          `'       ...
)";
    }
};