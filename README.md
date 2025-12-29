# DreamWest

# Game Introduction
Game Rules: Press 'a' to move left, press 'd' to move right

<img width="1707" height="898" alt="image" src="https://github.com/user-attachments/assets/0f3e07f4-4cf8-4e71-a408-1aca5a1f2f0a" />
If spiritual power is less than the minimum required for a skill or health drops below 0, it will be judged as failure.

Left skill deals 20 damage, consumes 10 spiritual power; Right skill deals 40 damage, consumes 15 spiritual power.

<img width="1790" height="979" alt="Screenshot 2025-12-29 145315" src="https://github.com/user-attachments/assets/fc8253d7-0686-471d-98a7-e0dfc00aeb41" />

# How to Run
The package includes a directly executable DreamWest.exe file.

# Development Environment
This project is developed using easyX and is recommended to be opened with Visual Studio 2022.

# Configuration for Running
Before running this project with VS in a new project, two settings need to be modified:

## 1. Character Set Settings
Right-click on the project -> Properties -> Advanced -> Character Set -> Select "Not Set" -> OK

## 2. Linker Configuration
Right-click on the project -> Properties -> Expand Linker -> Input under Linker -> Additional Dependencies -> Edit -> Add winmm.lib -> OK

# ----------------------------

# 游戏简介

游戏规则：按'a'向左移动，按'd'向右移动

灵力小于技能最少所需灵力或者血量小于0会被判为失败

左边技能造成伤害为20，消耗灵力10；右边技能造成伤害40，消耗灵力15

# 运行

内部配备有可直接运行的DreamWest.exe文件

# 开发环境

本项目采用easyX开发，建议通过Visual Studio 2022打开

# 运行配置

新建项目用VS运行本作品前需要先更改两个设置：

## 1. 字符集设置

在项目工程点击右键 -> 属性 -> 高级 -> 字符集 -> 选择"未设置" -> 确定

## 2. 链接器配置

在项目工程点击右键 -> 属性 -> 展开链接器 -> 链接器里的输入 -> 附加依赖项 -> 编辑 -> 将`winmm.lib`输入进去 -> 确定
