#include <iostream>
#include <string>
#include <magic_enum.hpp>
#include <frozen/unordered_map.h>
#include <frozen/string.h>

namespace detail
{
template<std::size_t ... Size>
struct num_tuple
{

};

template<std::size_t Prepend, typename T>
struct appender {};

template<std::size_t Prepend, std::size_t ... Sizes>
struct appender<Prepend, num_tuple<Sizes...>>
{
	using type = num_tuple<Prepend, Sizes...>;
};

template<std::size_t Size, std::size_t Counter = 0>
struct counter_tuple
{
	using type = typename appender<Counter, typename counter_tuple<Size, Counter+1>::type>::type;
};


template<std::size_t Size>
struct counter_tuple<Size, Size>
{
	using type = num_tuple<>;
};

}


template<typename T, std::size_t LL, std::size_t RL, std::size_t ... LLs, std::size_t ... RLs>
constexpr std::array<T, LL+RL> join(const std::array<T, LL> rhs, const std::array<T, RL> lhs, detail::num_tuple<LLs...>, detail::num_tuple<RLs...>)
{
	return {rhs[LLs]..., lhs[RLs]... };
};


template<typename T, std::size_t LL, std::size_t RL>
constexpr std::array<T, LL+RL> join(std::array<T, LL> rhs, std::array<T, RL> lhs)
{
	//using l_t = typename detail::counter_tuple<LL>::type;
	return join(rhs, lhs, typename detail::counter_tuple<LL>::type(), typename detail::counter_tuple<RL>::type());
}

enum class en
{
	aaa,
	bbb
};

//template <class Key, class Value,
//	std::size_t N,
//	std::size_t M,
//	class value_type = typename frozen::unordered_map<Key, Value, N>::value_type,
//	std::size_t ...I,
//	std::size_t ...J
//>
//constexpr std::vector<value_type> join(
//	const std::array<value_type, N>& map1,
//	const std::array<value_type, M>& map2,
//	std::index_sequence<I...>,
//	std::index_sequence<J...>
//)
//{
//	return {map1.at(I)..., map2.at(J)...};
//}
//
//template <class Key, class Value,
//	std::size_t N,
//	std::size_t M,
//	class value_type = typename frozen::unordered_map<Key, Value, N>::value_type,
//	typename Indices = std::make_index_sequence<N>,
//	typename Jndices = std::make_index_sequence<M>
//>
//constexpr std::vector<value_type> join(
//	const std::array<value_type, N>& map1,
//	const std::array<value_type, M>& map2
//)
//{
//	return join(map1, map2, Indices{}, Jndices{});
//}

int main()
{
	using namespace std::literals;

	std::string s = "aaa";
	std::string s2 = "nnn";

	//constexpr frozen::unordered_map<frozen::string, en, 2> m1 = {
	//	{"aaa", en::aaa},
	//	{"bbb", en::bbb}
	//};
	
	constexpr std::string_view sv = "aaab"sv;
	constexpr frozen::string st = sv;
	constexpr frozen::string st2 = "aaab";

	constexpr std::array<std::pair<frozen::string, en>, 2> m2 = {{
		{"a"sv, en::aaa},
		{"ab", en::aaa}
	}};

	constexpr std::array<std::pair<frozen::string, en>, 2> m3 = {{
		{"a2", en::bbb},
		{"ab2", en::aaa}
	}};

	auto m4 = join(m2, m3);
	//for(const auto& i: m4)
		//std::cout << i.first.data() << '\n';
	std::cout << (st2 == st);

	return 0;
}

