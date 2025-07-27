mov dptr,#4500H
movx a,@dptr
mov b,a
inc dptr
movx a,@dptr
add a,b
inc dptr
movx @dptr,a
end