import os
from django.shortcuts import redirect, render
from ctypes import *
libCalc = CDLL("./contacts/libcalci.so")

# Create your views here.
def home(request):
    file=open("./contacts/stdb.txt","r")
    content=file.read()
    content=content[:-1]
    context={"data":content.split('\n')}
    if(request.method=="POST"):
        fn=request.POST['fn']
        nn=request.POST['nn']
        ln=request.POST['ln']
        print(fn,ln,nn)
        if(len(nn)==10):
            if nn.isnumeric():
                content=content.split('\n')
                number=[item.split('\t', 2)[-1] for item in content]
                for i in number:
                    if(i==nn):
                        context["error"]="Mobile number already exist"
                        return render(request,"home.html",context)
                    else:
                        n=libCalc.insert(fn.encode('utf-8'),ln.encode('utf-8'),nn.encode('utf-8'))
                        
                        print(n)
                        
                        return redirect('home')
            context["error"]="Mobile number must contain numerics"
            return render(request,"home.html",context)
        context["error"]="Mobile must need 10 numbers"
        return render(request,"home.html",context)
    
    return render(request,"home.html",context)

def remove(request,no):
    no=no.split()
    fn=no[0]
    ln=no[1]
    nn=no[2]

    n=libCalc.delet(fn.encode('utf-8'),ln.encode('utf-8'),nn.encode('utf-8'))
    if n==1:
        print("yes")
    return redirect('home')