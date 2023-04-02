#include "Brain.hpp"

Brain::Brain(){
    _ideas[0] = "Take a nap in a sunbeam";
    _ideas[1] = "Play with a ball of yarn";
    _ideas[2] = "Catch a mouse";
    _ideas[3] = "Explore a new room";
    _ideas[4] = "Scratch on a scratching post";
    _ideas[5] = "Chase a laser pointer";
    _ideas[6] = "Drink from a running faucet";
    _ideas[7] = "Climb up a tree";
    _ideas[8] = "Watch birds outside";
    _ideas[9] = "Purr loudly when petted";
    _ideas[10] = "Play with a catnip toy";
    _ideas[11] = "Lick their fur clean";
    _ideas[12] = "Sit in a cardboard box";
    _ideas[13] = "Snuggle with their owner";
    _ideas[14] = "Knock objects off a table";
    _ideas[15] = "Bat at a toy mouse";
    _ideas[16] = "Hide under furniture";
    _ideas[17] = "Beg for treats";
    _ideas[18] = "Hunt a bug";
    _ideas[19] = "Cuddle with another cat";
    _ideas[20] = "Lounge on a windowsill";
    _ideas[21] = "Stretch their legs";
    _ideas[22] = "Meow for attention";
    _ideas[23] = "Scratch on furniture (naughty cat!)";
    _ideas[24] = "Investigate a paper bag";
    _ideas[25] = "Curl up in a cozy bed";
    _ideas[26] = "Climb on top of a bookshelf";
    _ideas[27] = "Play with a feather toy";
    _ideas[28] = "Hunt a toy mouse";
    _ideas[29] = "Chase a moth";
    _ideas[30] = "Sunbathe on a porch";
    _ideas[31] = "Explore a new outdoor area";
    _ideas[32] = "Nap in a cozy blanket";
    _ideas[33] = "Lick their paw";
    _ideas[34] = "Sit on a laptop keyboard (naughty cat!)";
    _ideas[35] = "Beg for belly rubs";
    _ideas[36] = "Watch fish in an aquarium";
    _ideas[37] = "Play with a shoelace";
    _ideas[38] = "Hide behind a curtain";
    _ideas[39] = "Climb on a book";
    _ideas[40] = "Sniff at a new plant";
    _ideas[41] = "Play with a paper ball";
    _ideas[42] = "Sit on a windowsill and watch the world go by";
    _ideas[43] = "Follow their owner around";
    _ideas[44] = "Chase a bug";
    _ideas[45] = "Bat at a ball";
    _ideas[46] = "Play with a tassel";
    _ideas[47] = "Hunt a toy bird";
    _ideas[48] = "Sit on a cat tower";
    _ideas[49] = "Drink milk";
    _ideas[50] = "Take a bath";
    _ideas[51] = "Roll around in catnip";
    _ideas[52] = "Play hide and seek";
    _ideas[53] = "Play with a ping pong ball";
    _ideas[54] = "Watch TV";
    _ideas[55] = "Groom their fur";
    _ideas[56] = "Nap in a warm spot";
    _ideas[57] = "Sit in a paper bag";
    _ideas[58] = "Play with a laser pointer";
    _ideas[59] = "Chase a fly";
    _ideas[60] = "Climb on top of a fridge";
    _ideas[61] = "Investigate a new toy";
    _ideas[62] = "Follow a light beam";
    _ideas[63] = "Sit on a lap";
    _ideas[64] = "Lick a bowl clean";
    _ideas[65] = "Play with a toy car";
    _ideas[66] = "Cuddle with a stuffed animal";
    _ideas[67] = "Hide in a closet";
    _ideas[68] = "Chase a light beam";
    _ideas[69] = "Watch birds through a window";
    _ideas[70] = "Bat at a toy bird";
    _ideas[71] = "Nap in a sunbeam";
    _ideas[72] = "Sit on a windowsill and people-watch";
    _ideas[73] = "Groom another cat";
    _ideas[74] = "Play with a toy snake";
    _ideas[75] = "Chase a shadow";
    _ideas[76] = "Climb on a curtain";
    _ideas[77] = "Explore a new outdoor area with their owner";
    _ideas[78] = "Snuggle with a blanket";
    _ideas[79] = "Sit in a shopping bag";
    _ideas[80] = "Play with a wind-up toy";
    _ideas[81] = "Hunt a toy bug";
    _ideas[82] = "Sit on a rug";
    _ideas[83] = "Play with a puzzle toy";
    _ideas[84] = "Chase a piece of string";
    _ideas[85] = "Groom their tail";
    _ideas[86] = "Hide under a bed";
    _ideas[87] = "Watch a thunderstorm";
    _ideas[88] = "Nap in a box";
    _ideas[89] = "Sit on a windowsill and listen to birds";
    _ideas[90] = "Play with a toy mouse that squeaks";
    _ideas[91] = "Chase a laser dot";
    _ideas[92] = "Hide in a paper bag";
    _ideas[93] = "Play with a toy spider";
    _ideas[94] = "Fetch a ball";
    _ideas[95] = "Fo for a walk outside";
    _ideas[96] = "Chew on a bone";
    _ideas[97] = "Play with another dog";
    _ideas[98] = "Dig a hole in the backyard";
    _ideas[99] = "Learn a new trick";
    std::cout << "Brain is constructed" << std::endl;
}
Brain::Brain(const Brain &other){
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    std::cout << "Copy of brain has been constructed" << std::endl;
}
Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}
Brain & Brain::operator = (const Brain &other){

    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}
std::string Brain::getIdea(int index)
{
    if (index < 0 || index > 99)
    {
        std::cout << "Wrong index" << std::endl;
        return NULL;
    }
    return (this->_ideas[index]);
}
void Brain::setIdea(int index, std::string idea)
{
    this->_ideas[index] = idea;
}