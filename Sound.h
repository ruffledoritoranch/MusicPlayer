/**
 * Sample API for <sound>
 */

#ifndef sound
#define sound

class sound /* is a */ : PARENT_CLASS
{
    /**
     * At a minimum, include:
     * 1) 1 or more Constructor (Apply Rule of 3 if needed); 
     * 2) Public Functions (minimum x2) including a non-trivial function
     *    (e.g. not a simple getter/setter)
     * 3) Private Data Members (minimum x2)
     */
public:
    sound();
    sound(int first, std::string second);

    /* may be virtual */ bool do_something(string s);
    int get_my_int();

private:

    int my_int;
    std:string my_str;
};

#endif 