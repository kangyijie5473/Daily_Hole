## sed是个好工具，我们大家都爱它 

想要替换，可以这样  

```
$ sed -i 's/old/new/g' file
```
想要递归替换，可以这样  

```
$ sed -i 's/old/new/h' `grep -rl old .`
```
如果old或者new是单引号（'） 呢？  
我们只能将它分开,再用\转义
```
$ sed -i 's/'\''/new/g' file
```
