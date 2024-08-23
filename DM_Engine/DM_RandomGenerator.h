//#pragma once
//#include "framework.h"
//
//
//
//
//
//namespace DM {
//	class RandomGenerator;
//}
//
//
//
//
//
//class DM::RandomGenerator
//{
//
//    template<class T>
//    using uniform_distribution =
//        typename std::conditional<
//        std::is_floating_point<T>::value,
//        std::uniform_real_distribution<T>,
//        typename std::conditional<
//        std::is_integral<T>::value,
//        std::uniform_int_distribution<T>,
//        void
//        >::type
//        >::type;
//
//public:
//
//	static void Initialize();
//
//    template <class T>
//    static T GetRandom(T min, T max)
//    {
//        RandomGenerator::Initialize();
//        return uniform_distribution<T>(min, max)(RandomGenerator::engine);
//    }
//
//
//private:
//
//	static thread_local std::mt19937 engine;
//
//};
//
//
//
//
//
////template <class T>
////T DM::RandomGenerator::GetRandom(T min, T max)
////{
////    RandomGenerator::Initialize();
////    return uniform_distribution<T>(min, max)(RandomGenerator::engine);
////}