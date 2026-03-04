\# 🏫 机房预约管理系统 (Computer Room Reservation System)



!\[C++](https://img.shields.io/badge/C++-11%2B-blue.svg)

!\[Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg)

!\[Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)



\## 📖 项目简介

本项目是一个基于 \*\*现代 C++\*\* 和 \*\*面向对象编程 (OOP)\*\* 思想构建的终端交互式管理系统。

旨在解决高校机房资源的预约、审核与分配问题。虽然运行在看似极简的黑框框终端里，但其底层包含了严谨的权限划分、状态机流转以及本地数据持久化机制。



> \*\*💡 开发者笔记\*\*：本项目是作为机械工程专业跨界软件开发的练手工程，重点不在于华丽的 UI，而在于深挖 C++ 底层逻辑、STL 容器的高效使用以及工业级代码的工程化封装。



---



\## ✨ 核心功能特性 (Features)



本项目实现了极其严格的三系角色权限隔离：



\* \*\*👨‍🎓 学生模块 (Student)\*\*

&nbsp;   \* 申请预约机房（系统自动校验机房容量与排班）。

&nbsp;   \* 查看自己的历史预约记录与当前状态（审核中/已通过/已拒绝）。

&nbsp;   \* 取消未审核的预约申请。

\* \*\*👨‍🏫 教师模块 (Teacher)\*\*

&nbsp;   \* 查看所有等待自己审核的预约申请。

&nbsp;   \* 一键通过或驳回学生的预约请求。

\* \*\*👨‍💻 管理员模块 (Admin)\*\*

&nbsp;   \* 添加、修改、删除学生和教师账号。

&nbsp;   \* 查看系统内所有的机房信息与预约总记录。

&nbsp;   \* 一键清空系统底表的危险操作权限。



---



\## 🛠️ 技术栈与底层架构 (Tech Stack)



\* \*\*开发语言\*\*: C++ (应用 C++11/14 现代特性)

\* \*\*核心技术点\*\*:

&nbsp;   \* \*\*面向对象设计 (OOP)\*\*：利用类的继承与多态，完美抽象多角色业务逻辑。

&nbsp;   \* \*\*STL 深度应用\*\*：高频使用 `vector`, `map`, `deque` 容器，配合 `lambda` 表达式与 `algorithm` 算法库完成数据的排序、筛选与降维打击。

&nbsp;   \* \*\*流式 I/O 与数据持久化\*\*：告别传统的 C 语言指针操作，全面拥抱 `ifstream` / `ofstream`，配合自定义的分隔符解析算法，实现数据的断电不丢失。

&nbsp;   \* \*\*内存与异常管理\*\*：严防嵌套循环引发的迭代器失效与变量遮蔽 (Variable Shadowing) 问题。



---



\## 🚀 极速启动 (How to Run)



本项目支持在 Windows (Visual Studio) 和 Linux (g++ / WSL) 双环境下无缝编译运行。



\### 🐧 Linux / WSL 环境编译（推荐体验）

打开终端，将当前路径切换至项目根目录，敲下这行极客指令：

```bash

\# 编译所有源文件并生成可执行程序

g++ main.cpp speechManager.cpp -o ReservationSystem -std=c++11



\# 运行系统

./ReservationSystem

