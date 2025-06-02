include<iostream>
using namespace std;


template<class T >

class double_linked {

	struct node {
		T data;
		node* prev; node* next;
		node(T t, node* p, node* n) :data(t), prev(p), next(n) {} 
		


	};

	node* head;
	node* tail;

public:
	double_linked() : head(NULL), tail(NULL) {
	}

	template <int N  >
	double_linked(T(&arr)[N]) : head(NULL), tail(NULL) {
		for (int i(0); i != N; ++i) {
			push_back(arr[i]);

		}
	}
		bool empty() const {
			return (!head || !tail);
		}

		operator bool() const {
			return !empty();
		}
		void push_back(T);
		void push_front(T);


		T pop_back();
		T pop_front();

		~double_linked()
		{
			while (head) {
				node* temp(head);
				head = head->next;
				delete temp;

			}


		}
	};


	template <class T>
	void double_linked <T> :: push_back(T data ){
		tail = new node(data, tail, NULL);
		if(tail->prev)
			tail->prev->next = tail;

			if (empty())
				head = tail;



			}


		template<class T >
			void double_linked <T> ::push_front(T data) {

			head = new node(data, NULL, head);
			if(head->next)
				head->next->prev = head;

			if (empty())
				tail = head;

		}

		template<typename T> T double_linked <T>  ::pop_back()
		{

			if (empty())

				throw (" double_linked : list empty");
			node* temp(tail);
			T data(tail->data);

			tail = tail->prev;

			if (tail)
				tail->next = NULL;
			else  
				head  = NULL;
			delete temp;
			return data;

		}



		template<class T> 
		T double_linked <T> :: pop_front(){
			if (empty())
				throw(" doublwe_linked : list empty ");


					node* temp(head);
				T data(head->data);

				head = head->next;

				if (head)

					head->prev = NULL;


				else
					tail = NULL;

				delete temp;
				return data;



			}


			int main() {


				/*int arr[] = { 4,6,8,32,19 };
				double_linked <int > dlist(arr);

				dlist.push_back(11);

				dlist.push_front(100);
				while(dlist)
					cout << dlist.pop_back() << "  ";*/



			
				
					long long arr[] = { 1000000000001, 2000000000002, 3000000000003, 4000000000004 };

				
					double_linked<long long> dlist(arr);

					dlist.push_back(5000000000005);
					dlist.push_front(9999999999999);

				
					cout << "List after insertions: ";
					while (dlist)
						cout << dlist.pop_front() << " ";

					cout << endl;

					return 0;
				}
				