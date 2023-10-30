#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void PrintVectorPart(std::vector<T>&& numbers) {
	std::vector<int>::iterator it = numbers.begin();
	std::vector<T> result;
	bool flag = false;
	while(it!= numbers.end()){
		if(*it < 0){
			flag = true;
			break;
		}
		result.push_back(*it);
		it++;
	}
	if (flag) std::sort(result.begin(), result.end());

	std::vector<int>::reverse_iterator revIT = result.rbegin();
	for(;revIT != result.rend(); revIT++){
		std::cout << *revIT << " ";
	}
}
int main()
{
	PrintVectorPart<int>({ 6, 1, 8, -5, 4 });  //  1 6 8 (Ответ неправильный. По заданию сказано вывести массив 
                                               //отсортированный в обратном порядке поэтому правильный ответ 8 6 1)
	std::cout << std::endl;
	PrintVectorPart<int>({ -6, 1, 8, -5, 4 });  //  ничего не выведется
	std::cout << std::endl;
	PrintVectorPart<int>({ 6, 1, 8, 5, 4 });  //  4 5 8 1 6
	std::cout << std::endl;
	return 0;
}