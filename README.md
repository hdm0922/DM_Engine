직접 만들어 보는 게임 엔진입니다. (C++)

[Error Code]



<error C2059> : 'namespace'

원인 : 특정 헤더파일의 클래스 선언 이후 세미콜론이 없었다.

해결 : 소스 코드에 세미콜론 추가



<error C2664> : 형변환 실패

원인 :

```C++
DM::UI_Status::UI_Status(const std::wstring& name)
	: UI_Frame(name)
{
	UI_Button* closeButton = this->ObjectTree<UI_Frame>::Create<UI_Button>();
}
```

```C++
template<typename T> template <typename T2>
inline T2* DM::ObjectTree<T>::Create()
{
	T2* subNode = new T2();

  subNode->ObjectTree<UI_Frame>::SetParent(this); // ERROR!

	this->subNodes.push_back(static_cast<T*>(subNode));

	return subNode;
}
```

문제의 코드는 아래이다.

```C++
subNode->ObjectTree<UI_Frame>::SetParent(this);
```

나는 UI_Status 객체에서 호출했기 때문에, this가 UI_Status의 모든 정보(UI_Frame을 상속받았기에 UI_Frame도 물론 해당된다)를 가질 것이라 생각했다.
그러나 실제 로직은 ObjectTree<UI_Frame> 클래스에서 실행되기 때문에, 컴퓨터는 오로지 ObjectTree<UI_Frame>으로만 해석, 형변환 불가능하다는 C2664 에러를 띄웠다.

해결 :

결국 "this" 가 UI_Frame의 정보를 가지면 되기 때문에, UI_Status의 생성자에서 SetParent를 해줬다.

```C++
DM::UI_Status::UI_Status(const std::wstring& name)
	: UI_Frame(name)
{
	UI_Button* closeButton = this->ObjectTree<UI_Frame>::Create<UI_Button>();
  closeButton->ObjectTree<UI_Frame>::SetParent(this);
}
```

```C++
template<typename T> template <typename T2>
inline T2* DM::ObjectTree<T>::Create()
{
	T2* subNode = new T2();

	this->subNodes.push_back(static_cast<T*>(subNode));

	return subNode;
}
```

<error C2338> : std::map 선언 후 빌드가 안됨

원인 : std::map의 선언 형식이 잘못됐다

```C++
std::map<const std::wstring&, Resource*> resources;
```

해결 : std::map의 Key로 사용될 타입이 올바르지 않았다. 참조자를 빼고 선언하면 문제가 해결된다.

```C++
std::map<const std::wstring, Resource*> resources;
```
