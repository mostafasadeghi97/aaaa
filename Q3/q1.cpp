
#include<iostream>
#include<utility>
#include <functional>
#include<algorithm>
#include<string>
#include<set>
#include<random>

//================= MOSTAFA SADEGHI   9423067 ================



class myclass {
public:
	myclass(double a): n{a} {}
	bool operator() (int i,int j) { return (std::abs(i-n)<std::abs(j-n));}
private:
	double n;
};


bool IsGreaterThan3(int i) 
{ 
    return (i > 3); 
} 
  

int main() { 
	
	// std::transform(myv1.begin(), myv1.end(), myv1.begin(),
    //            std::bind(std::multiplies<T>(), std::placeholders::_1, 3)); 
	

	std::srand(time(NULL)); 
	std::vector<int> a(50);
	std::vector<int> b(50);
	for (size_t i = 0; i < 50; i++)
	{
		b[i]=(std::rand()%(50) +1);
	}

	
	
	std::set<int> cc( b.begin(), b.end() );
	std::set<int> dd;
	while (true)
	{
		if (dd.size() == 50)
		{
			break;
		}
		dd.insert(std::rand()%(50)+1);
		
	}

	std::vector<int> qq(cc.begin(), cc.end());
	std::vector<int> qq2(dd.begin(), dd.end());
	
	// std :: set <int>::iterator pend2; 
      
	// std::set<int>:: iterator it; 
	// it=fooSet.upper_bound(3);

    // //Erasing
	// // std::set<int>:: iterator it;

    // fooSet.erase(it,fooSet.end());
	// // 
	// for(std::set<int>::iterator it1=fooSet.begin(); it1!=fooSet.end(); ++it1)
    //   std::cout<< *it1 << "\n";
	int myconstant{2};
	std::transform(qq.begin(), qq.end(), qq.begin(), [myconstant](auto& c){return std::pow(c,myconstant);});
	std::transform(qq2.begin(), qq2.end(), qq2.begin(), [myconstant](auto& c){return std::pow(c,myconstant);});

	double sum1 = accumulate( qq.begin(), qq.end(), 0.0);
	double sum2 = accumulate( qq2.begin(), qq2.end(), 0.0);
	std::cout << sum2 - sum1 << std::endl;
	// // for(auto a:myarray){
	// // 	std::cout << a << std::endl;
	// // }

	// double average = accumulate( myarray.begin(), myarray.end(), 0.0)/myarray.size();
	// std::cout << average << std::endl;
	// std::sort(myarray.begin(), myarray.end(), myclass{average});
	// for(auto a:b){
	// 	std::cout << a << ' ';
	// }
	// std::cout << std::endl;
	// for(auto a:cc){
	// 	std::cout << a << ' ';
	// }
	// std::cout << std::endl;
	// for(auto a:dd){
	// 	std::cout << a << ' ';
	// }
	return 0;
} 
