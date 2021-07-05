% membaca image
I=imread('stego_image.png');
var123=[];
final_msg=[];
i1=1;
checker='000000000000000000000000000000';
msg='';
while(i1<=510)
    for j1=1:3:510
        
        pixel_count=0;
        for i=i1:i1+2
            for j=j1:j1+2
                
                pixel_count=pixel_count+1;
                % mencari bagian tengah blok 3x3
                if(pixel_count==5)
                    A1=i;
                    A2=j;
                    % mendapatkan bentuk biner dari bagian tengah blok 3x3
                    m1=de2bi(I(i,j),8);
                    for loop=3:-1:1
                        % menyimpan pesan kedalam variabel msg
                        msg=strcat(msg,num2str(m1(loop)));
                        var123=strfind(msg,checker);
                        if(length(var123)>=1)
                            break
                        end
                        
                    end
                    if(length(var123)>=1)
                        break
                    end
                    
                
                end
            end
            if(length(var123)>=1)
                break
            end
        end
        inner_loop=0;
        for x1=i1:i1+2
            for x2=j1:j1+2
                inner_loop=inner_loop+1;
                if(inner_loop~=5)
                    % menghitung nilai d1-d8
                    if(I(x1,x2)>I(A1,A2))
                        di=I(x1,x2)-I(A1,A2);
                    elseif(I(x1,x2)==I(A1,A2))
                        di=0;
                    else
                        di=I(A1,A2)-I(x1,x2);
                    end
                    
                    % menentukan range untuk d1-d8 menggunakan "range
                    % table"
                    if(di<8)
                        L=0;
                        ti=3;
                    elseif(di>7 && di<16)
                        L=8;
                        ti=3;
                    elseif(di>15 && di<32)
                        L=16;
                        ti=3;
                    elseif(di>31 && di<64)
                        L=32;
                        ti=3;
                    elseif(di>63 && di<128)
                        L=64;
                        ti=4;
                    else
                        L=128;
                        ti=4;
                    end
                    
                    % mencari nilai S1 sampai S8
                    S=di-L;
                    % mengubah desimal ke dalam bentuk biner
                    binary_form=fliplr(de2bi(S,ti));
                    
                    for k=1:ti
                        % menyimpan pesan kedalam variabel msg
                        msg=strcat(msg,num2str(binary_form(k)));
                        var123=strfind(msg,checker);
                        if(length(var123)>=1)
                            break
                        end
                    end
                    if(length(var123)>=1)
                        break
                    end
                end

            end
            if(length(var123)>=1)
                break
            end
        end
        if(length(var123)>=1)
            break
        end
    end
    if(length(var123)>=1)
        break
    
    end
    
    i1=i1+3;
end
lkj=var123(1);
lkj=lkj+6;
msg
msg=msg(1:lkj);
msg
final_msg=[];
ccc=0;
% menghitung panjang pesan
len_msg=floor(length(msg)/8);
for outer_loop=1:len_msg
    ccc=ccc+1;
    % mengubah pesan dari bentuk biner ke desimal
    final_msg(outer_loop)=bin2dec(fliplr(msg(ccc:ccc+7)));
   
        
    ccc=ccc+7;
end
% output pesan dalam ascii
final_msg
% output pesan original
char(final_msg)
