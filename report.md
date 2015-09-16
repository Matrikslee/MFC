# Visual C++ 程序设计综合实训 实训报告

|项目|内容|
|---|----|
|姓名|李成|
|学号|14090041016|
|专业年级|2014级自动化|
|指导教师|李庆忠|
|实训日期|2015年 8月24日~9月6日|

## 实训介绍

在本次C++实训课程中，我使用`Visual C++ 6.0`集成开发环境（IDE）作为我的开发工具。在本次实训中，我主要学习了利用`Visual C++`软件中的MFC类库，完成Windows编程。其中我们重点学习了文档、视图、菜单、对话框及其控件的创建方式。
在正式开始学习之前，我先学习了Windows编程所使用的事件驱动程序设计思想。在事件驱动的程序结构中，程序的控制流程不再由事件的预定发生顺序来决定，而是由实际运行时各种事件的实际发生来触发，而事件的发生可能是随机的、不确定的、并没有预定的顺序。事件驱动的程序允许用户用各种合理的顺序来安排程序的流程。对于需要用户交互的应用程序来说，事件驱动的程序设计有着传统程序设计方法无法替代的优点。事件驱动是一种面向用户的程序设计方法，其使用了消息队列来实现事件处理的功能，在程序设计过程中除了完成所需要的程序功能之外，更多的考虑了用户可能的各种输入（消息），并有针对性地设计相应的处理程序。事件驱动程序设计也是一种“被动”式的程序设计方法，程序开始运行时，处于等待消息状态，然后取得消息并对其作出相应反应，处理完毕后又返回处于等待消息的状态。
在本次实训中，我学会了如何使用`MFC（Microsoft Foundation Class）`来进行windows程序开发。在这里，MFC是Microsoft提供的一个基础类库, 可用于方便开发Windows 应用程序。封装了大部分`Windows API (Application Programming Interface)`应用程序接口，可大大简化Windows编程工作。

## 二、实训要求

在老师讲解了每章的内容之后，通过对教材里面每章例题进行自主学习，并且在课后独立完成相应的练习题。该模式下的学习方法可以让我学到更多的东西，注重实践编程，真正理解所学知识。通过独立自主的完成课后练习题代码的编写，达到了即学即用，学以致用的目的。

## 三、实训内容及结

### 第十章：Windows编程

#### 内容提要

- Visual C++开发环境
- Windows编程基本思想
- MFC编程框架
- 单文档界面（SDI）应用程序
- 在窗口客户区输出文字图形
- 消息处理函数编写
- 用户界面对象基本概念
- Windows 数据类型与变量命名规则

#### 详细内容

1. 使用视图类成员函数OnDraw()进行客户区的图形绘制

	成员函数OnDraw()是视图类的一个重要的成员函数。它管理程序视图界面客户区的图形显示。在第十章我就是通过学习在OnDraw()函数内填写代码来实现在客户区显示一定的图形和图案。
	
	pDC是MFC程序视图类的成员函数OnDraw()的一个指向CDC类的指针，我们可以通过它调用GDI函数可以进行绘图操作。

	这里我主要学习了以下几个函数的使用:

	- MoveTo()
		该函数的原型有两个：

		- CPoint MoveTo(int x, int y);
		- CPoint MoveTo(POINT point);
	
		它接收两个坐标变量或者一个POINT类变量做为参数，返回一个CPoint类，作用是修改直线绘图的起点。

	- LineTo()
		该函数的原型也有两个:

		- BOOL LineTo(int x, int y);
		- BOOL LineTo(POINT point);
	
		它的参数同MoveTo()一样，返回一个BOOL类型的值，作用是在客户区绘出一条直线。

	- Rectangle()
		该函数的原型有两个:
		
		- BOOL Rectangle(int x1, int y1, int x2, int y2);
		- BOOL Rectangle(LPCRECT lpRect);
		
		它接收四个参数分别为两个坐标点的横纵坐标值或者一个LPCRECT类型的变量，返回一个BOOL类型的值，作用是在客户区绘出一个矩形。

	- TextOut()
		该函数的原型只有一个:
		
		- BOOL TextOut(int x, int y, LPCTSTR lpszString);
		
		它接收三个参数分别为前两个整型变量为一个坐标点的横纵坐标值，第三个为一个LPCTSTR类型的字符串变量,返回BOOL类型的值，作用为将传入的字符串输出到客户区。前一个坐标点为字符串的起点，字符串从左往右输出。

	- Ellipse()
		该函数的原型有两个：
		
		- BOOL Ellipse(int x1, int y1, int x2, int y2);
		- BOOL Ellipse(LPCRECT lpRect);
		
		它接收的参数与Rectangle()函数的参数一样，返回BOOL类型的值，作用为在客户区绘制传入参数代表的矩形的内切椭圆。

2. 使用类向导添加消息处理函数

#### 习题解析

这里只展示其中两道课后练习题（习题10.3和习题10.5）的编码过程。
	
* 习题10.3解答过程
	习题10.3要求：编写程序在窗口客户区绘制一副风景画（应包括太阳、山、房屋等，只用线条即可）。
	
	1. 第一步、使用应用程序向导(App Wizard)创建单文档（SDI）应用程序。获得集成开发环境软件自动生成的若干代码文件。
	
	2. 第二步、在程序的视图类源文件（*View.cpp）OnDraw()函数处填写绘制太阳的代码
		```cpp

		{
			// 太阳
			int left = 700, right = left + 100;
			int top = 80, bottom = top + 100;
			pDC->Ellipse(left, top, right, bottom);
			const int xCircle = (left + right) / 2;
			const int yCircle = (top + bottom) / 2;
			pDC->Ellipse(xCircle-5, yCircle-5, xCircle+5, yCircle+5);
			const double PI = 3.1415926;
			for (int i = 0; i < 16; ++i) {
				const int len = 60;
				const int xLen = (int)(len*cos(i*PI / 8));
				const int yLen = (int)(len*sin(i*PI / 8));
				pDC->MoveTo(xCircle + xLen, yCircle + yLen);
				pDC->LineTo(xCircle + 2*xLen, yCircle + 2*yLen);
			}
		}
		```

	3. 第三步、在程序的视图类源文件（*View.cpp）OnDraw()函数处填写绘制山的代码
		
		```cpp
		{
			// 山
			int x = 200, y = 100;
			const int dx = 40;
			const int dy = 150;
			pDC->MoveTo(x, y);
			x = x - dx;
			y = y + dy;
			pDC->LineTo(x, y);
			x = x - (int)(dx*0.7);
			y = y - dy / 2;
			pDC->LineTo(x, y);
			x = x - (int)(dx*0.5);
			y = y + (int)(dy*0.7);
			pDC->LineTo(x, y);
			const int left = x;
			const int bottom = y;
			x = 200, y = 100;
			pDC->MoveTo(x, y);
			x = x + dx;
			y = y + dy;
			pDC->LineTo(x, y);
			x = x + (int)(dx*0.7);
			y = y - dy / 2;
			pDC->LineTo(x, y);
			x = x + (int)(dx*0.5);
			y = y + (int)(dy*0.7);
			pDC->LineTo(x, y);
			const int right = x;
			pDC->MoveTo(left, bottom);
			pDC->LineTo(right, bottom);
		}
		```
		
	4. 第三步、在程序的视图类源文件（*View.cpp）OnDraw()函数处填写绘制房子的代码
		
		```cpp
		{
			// 房子
			const int top = 250, center = 500;
			int x = center, y = top;
			const int dx = 50, dy = 50;
			const int left = x - dx;
			const int right = x + dx;
			const int middle = y + dy;
			pDC->MoveTo(x, y);
			pDC->LineTo(left, middle);
			pDC->LineTo(left, middle + (int)(dy*1.2));
			pDC->MoveTo(x, y);
			pDC->LineTo(right, middle);
			pDC->LineTo(right, middle + (int)(dy*1.2));
			pDC->LineTo(left, middle + (int)(dy*1.2));
			pDC->MoveTo(right - dx / 2, y + dy / 2);
			pDC->LineTo(right - dx / 2, y);
			pDC->LineTo(x + (int)(dx*0.7), y);
			pDC->LineTo(x + (int)(dx*0.7), y + (int)(dy*0.7));
			pDC->Rectangle(left + 10, middle, left + 40, middle + 40);
		}
		```

	程序效果截图
	![程序效果截图](http://ww3.sinaimg.cn/large/0063AxbLjw1ew3g0dynplj30sh0fg0ue.jpg)

* 习题10.5解答过程
	
	习题10.5要求：编写程序在屏幕中画一个矩形，并编写鼠标左键处理消息：在矩形内单击鼠标左键时，显示“击中矩形”，否则不显示。在矩形外单击鼠标左键时，你能把矩形移动到左键单击的位置吗？

	1. 第一步、使用应用程序向导(App Wizard)创建单文档（SDI）应用程序。获得集成开发环境软件自动生成的若干代码文件。
	
	2. 第二步、在视图类头文件（*View.h）的类声明处声明一个成员变量m_rectMyRectangle
		
		```cpp
		...
		// 属性
		public:
			CFifthDoc* GetDocument() const;
			CRect m_rectMyRectangle;
		// 操作
		public:
		...
		```

	3. 第三步、在视图类源文件（*View.cpp）的视图类构造函数处添加代码
		
		```cpp
		CMyView::CMyView()
		{
			// TODO: 在此处添加构造代码
			m_rectMyRectangle = CRect(0, 0, 100, 200);
		}
		```

	4. 第四步、在视图类源文件（*View.cpp）OnDraw函数处添加代码
		
		```cpp
		void CMyView::OnDraw(CDC* pDC)
		{
			CFifthDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (!pDoc)
				return;
			// TODO: 在此处为本机数据添加绘制代码
			pDC->Rectangle(this->m_rectMyRectangle);
		}
		```

	5. 第五步、使用类向导（Class Wizard）为视图类添加消息WM_LBUTTONDOWN的消息处理函数并在其中添加消息处理代码

		```cpp
		void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
		{
			// TODO: 在此添加消息处理程序代码和/或调用默认值
			CRect& rectTemp = this->m_rectMyRectangle;
			if ( rectTemp.PtInRect(point) ) {
				MessageBox("击中矩形!");
			} else {
				int x = point.x, y = point.y;
				rectTemp = CRect(x, y, x + 100, y + 200);
			}
			Invalidate();
			CView::OnLButtonDown(nFlags, point);
		}
		```
	程序效果截图
	![程序效果截图](http://ww1.sinaimg.cn/large/0063AxbLjw1ew3h12435rj30sh0fg3zv.jpg)

### 第十一章：文档/试图结构


#### 内容提要

* 理解文档/视图的概念，即文档类和视图类的关系。
* 深入学习视图类以及其成员变量和成员函数的功能并熟练使用。
* 深入学习文档类以及其成员变量和成员函数的功能并熟练使用。
* 理解文档/视图类之间的协作关系,并做到能够熟练的使用文档类进行数据存储,然后在视图类中使用，以达到数据和功能相分离的目标。
* 通过视图类成员函数的调用使客户区重绘。
* 学习定时器消息的功能和使用。

#### 详细内容

1.  熟悉MFC两种类型的文档/视图结构：

	* 单文档界面（Single Document Interface， SDI）应用程序
	* 多文档界面（Multiple Document Interface， MDI）应用程序

2.  使用文档类存储数据并对变量初始化以及修改。
	
	通过在文档类头文件的类声明中添加成员，并在其源文件中添加相应的初始化代码或者定义代码，来达到数据存储的目的。
	
	文档类的成员变量可以通过在成员函数OnNewDocument()的定义内填写代码进行初始化。

3.  在视图类通过成员函数GetDocumen()函数获取文档类指针以达到访问文档类数据的目的。
	
	该函数不接收任何参数且返回一个文档类的指针，作用为在视图类内提供文档类数据的访问接口。

4.  在视图类内通过调用Invalidate()函数或者InvalidateRect()函数来达到使客户区重绘的目的：
	- Invalidate()
		该函数的原型为：

		- void Invalidate(BOOL bErase = TRUE);
		
		该函数接收一个默认值为TRUE的BOOL类型参数,作用为调用OnDraw()函数将客户区进行重新绘制。如果参数为真，擦除背景重绘，否则不擦除背景重绘。

	- InvalidateRect()
		该函数的原型为：

		- void InvalidateRect(LPCRECT lpRect, BOOL bErase = TRUE);
		
		该函数接收两个参数分别为一个LPCRECT类型的变量表示需要进行重绘的区域， 一个默认值为TRUE的BOOL类型变量（为真则擦除背景重绘，否则不擦除背景重绘。）

5. 	定时器消息的设置和使用
	
	定时器是非常有用的编程元素。定时器消息为WM_TIMER，使用定时器的步骤有三个：

	1.  设置定时器，该步骤通过成员函数SetTimer()完成。其原型为：
		- UINT SetTimer(UINT nIDEvent, UINT nElapse, void* lpfnTimer);
	
	2.  重载消息处理函数OnTimer()（可以由Class Wizard自动编制），其原型为：
		- afx_msg void OnTimer(UINT nIDEvent);
		
		其中参数nIDEvent为定时器标识符。若在程序中设置了多个定时器消息，则在重载的OnTimer()函数中可以根据定时器标识符来区分不同的定时器周期。

	3.  定时器用完后要即使释放。释放定时器使用成员函数KillTimer()，其原型为：
		- BOOL KillTimer(int nIDEvent);
	
		其中nIDEvent为要删除的定时器标识符。

#### 习题解答

* 	习题11.1编码过程

	习题11.1要求：在例11.6的基础上增加用鼠标右键删除泡泡的功能。

	1. 	第一步、使用应用程序向导（APP Wizard）生成文档/视图结构的程序框架。
	2. 	第二步、修改文档类的声明（头文件），加入宏定义以及变量定义。
		
		```cpp
		#define MAX_BUBBLE 250
		class CMyDoc : public CDocument
		{
		protected: // 仅从序列化创建
			CMyDoc();
			DECLARE_DYNCREATE(CMyDoc)
		// 特性
		public:
			CRect m_rectBubble[MAX_BUBBLE];
			int m_nBubbleCount;
		// 操作
		public:

		//...(省略文档类的其它定义语句).
		};
		```
	3. 	第三步、为文档类的成员变量在成员函数OnNewDocument()添加初始化代码：
		
		```cpp
		BOOL CMyDoc::OnNewDocument()
		{
			if (!CDocument::OnNewDocument())
				return FALSE;
			m_nBubbleCount = 0;
			// TODO: 在此添加重新初始化代码
			// (SDI 文档将重用该文档)
			return TRUE;
		}
		```

	4. 	第四步、修改视图类成员函数OnDraw()，添加显示泡泡的代码：
		
		```cpp
		void CMyView::OnDraw(CDC* pDC)
		{
			CMyDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (!pDoc)
				return;
			for (int i = 0; i < pDoc->m_nBubbleCount; ++i) {
				pDC->Ellipse(pDoc->m_rectBubble[i]);
			}
			// TODO: 在此处为本机数据添加绘制代码
		}
		```
	5. 	第五步、使用类向导（Class Wizard）为视图类添加鼠标左键的消息并对消息处理函数进行编码：
		
		```cpp
		void CMyView::OnLButtonDown(UINT nFlags, CPoint point)
		{
			// TODO: 在此添加消息处理程序代码和/或调用默认值
			CMyDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (pDoc->m_nBubbleCount < MAX_BUBBLE) {
				int r = rand() % 50 + 10;
				CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);
				pDoc->m_rectBubble[pDoc->m_nBubbleCount] = rect;
				++pDoc->m_nBubbleCount;
				pDoc->SetModifiedFlag();
				InvalidateRect(rect, FALSE);
			}
			CView::OnLButtonDown(nFlags, point);
		}
		```
		
		实现点击鼠标左键显示泡泡的功能。

	6. 	第六步、使用类向导（Class Wizard）为视图类添加鼠标右键的消息并对消息处理函数进行编码：

		```cpp
		void CMyView::OnRButtonDown(UINT nFlags, CPoint point)
		{
			// TODO: 在此添加消息处理程序代码和/或调用默认值
			CMyDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (pDoc->m_nBubbleCount == 0) {
				MessageBox("没有泡泡了,,,~~");
			} else {
				bool isDeleted = false;
				for (int i = pDoc->m_nBubbleCount - 1; i >= 0; --i) {\
					if (pDoc->m_rectBubble[i].PtInRect(point)) {
						CRect tmp = pDoc->m_rectBubble[i];
						for (int j = i; j < pDoc->m_nBubbleCount - 1; ++j) {
							pDoc->m_rectBubble[j] = pDoc->m_rectBubble[j + 1];
						}
						--pDoc->m_nBubbleCount;
						InvalidateRect(tmp, TRUE);
						isDeleted = true;
						break;
					}
				}
				if (!isDeleted) {
					MessageBox("你没有点到泡泡哦~,~");
				}
			}
			CView::OnRButtonDown(nFlags, point);
		}
		```

		实现删除泡泡的功能。

		程序效果截图：

		![程序效果截图](http://ww2.sinaimg.cn/large/0063AxbLgw1ew4ayiwqusj30sh0fg41i.jpg)

### 第十二章：图形设备接口和资源

#### 内容提要

#### 详细内容

### 第十三章：对话框

#### 内容提要

#### 详细内容

### 第十四章：控件

#### 内容提要

#### 详细内容

## 总结

通过这一次的C++实训课程的学习，我系统地学习了关于MFC的知识，可以掌握文档、视图、菜单、对话框及其控件的创建方式并且活用他们达到编程实用的目的。
VC++ 6.0是一个十分强大的集成开发环境，其内容丰富、强大，而作为初学者的我只是学会如何使用其一小部分功能，相信在将来的学习过程中，通过深入该款开发系统的学习，我能够利用该开发系统完成更多更好的程序设计和编码。
