#include <iostream>
#include <random>

// TIP it's important to have:
//<br> the <a href="https://en.cppreference.com/cpp/header/iostream">iostream library</a> called with std (for "standard") to have outputs and inputs
//<br> the <a href="https://en.cppreference.com/cpp/header/random">random library</a> called with std (for "standard") to have random generators
//<br> (they will light up when used)
//<p> </p>
// TIP <b> Simple Dice Roller Code (learning C++)</b>
//<br> The documentation at <a href="https://en.cppreference.com/cpp/numeric/random/uniform_int_distribution">cppreference.com</a> explains perfectly how to have a dice roller.
//<br>  Check it out!!!!

int main()
{
    // TIP <a href="https://en.cppreference.com/cpp/numeric/random/random_device">random_device</a> gives you a random seed.
    //<br> rd is a variable containing a "random_device" object which kind of work like a function.
    //<br> Calling rd() will give you a random seed.
    std::random_device rd; // !! This only setup the random device variable

    // TIP <a href="https://cplusplus.com/reference/random/mt19937/">mt19937</a> or "Mersenne Twister 19937 generator"
    // is another class object, it needs a seed to initialize like so gen(seed).
    //<br> Once initialized, calling gen() will give you a random number similar to rd(), but it is less performance heavy to call.
    std::mt19937 gen(rd()); // !! This make the random device variable actually work and generate a seed
                               // the seed is then given to the Mersenne Twister 19937 generator


    // TIP Testing how rd() and gen() works, comment/uncomment to test out the code
    /*std::cout << rd(); // performance heavy random number generation
    std::cout << "\nBREAK LINE \n";
    std::cout << gen(); // performance light random number generation*/

    // TIP <a href="https://en.cppreference.com/cpp/numeric/random/uniform_int_distribution">uniform_int_distribution</a> is also a class object, it needs a minimum and a maximum value to initialize like so distrib(min, max).
    //<br> Once initialized, you have to give it a random number generator: distrib(gen),
    //<br> which will return a random number between the min and max value.

    std::uniform_int_distribution<int> distrib(1,6); // Setup the variable to be an int only between 1 and 6

    std::cout << distrib(gen); // Use distrib with the random number generator from earlier

    // TIP <b> Alternatives!! </b>
    //<br> uniform_int_distribution is the BEST solution since it give each numbers an equal chance of showing up by taking into account the flaws in the number generator.
    //But it's also possible to use the...
    //<br> <b> -Modulo </b>
    int modulo_result = (gen() % 6) + 1; // modulo of 6 give a range of [0, 5] so we add +1

    std::cout << "\nModulo:\n";
    std::cout << modulo_result;

     // TIP if the random number is already close to the desired range and we don't care about even chances we can also use...
     //<br> <b> <a href="https://en.cppreference.com/cpp/algorithm/clamp">-Clamp</a></b> (please don't use it for a dice roller)
    int clamped_result = std::clamp<unsigned int>(gen(), 1, 6);

    //!! We need to specify the type of variable for the clamp function to unsigned int
    // since it works only with the same variable type and gen() is a "unsigned int" variable
    // and 1 and 6 will default to "int" variable

    std::cout << "\nClamped:\n";
    std::cout << clamped_result; // will always print out 6 since gen() usually generate big numbers
}


