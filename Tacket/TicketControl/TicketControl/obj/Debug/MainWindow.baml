   M S B A M L   `   `   `  ����H  DTicketControl, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null-clr-namespace:TicketControlTicketControl  5   	       TicketControl.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   -localclr-namespace:TicketControl     5   	     � 
ResizeMode$  NoResize=�5   	    � Title$ 我的车票--登录��5	   	   $	��350��6   $	��525��6'   .��5
      �  � ColumnDefinitions 5   
   �� 5      $
��115* �6   �� 5      $
��283* �6   �� 5      $
��119* �6    � RowDefinitions 5   
   �� 5      $
��121* �6   �� 5      $	��54* �6   �� 5      $	��55* �6   �� 5      $	��89* �6   .+�5   
   �� -   5         ��Name$ tileBlockBox��5      $��我的车票客户端��6*   $��1��69   $��Center=�6I   $��Center=�6f   $��25(�6�   �� 5   
   -   5        $ useNameTextBlock��5      $��
用户名:��6.   $��0��6:   $��1��6J   $��Right=�6W   $��Center=�6s   �� 5   
   -   5        $ paswordTextBlock��5      $��密码:��6.   $��0��69   $��2��6I   $��Right=�6V   $��Center=�6r   �� 5   
   -   5         ��Name$ useNameTextBox��5      $��1��6*   $��1��6:   $��10,15q�6G   �� 5   
   -   5        $ paswordTextBox��5      $��1��6*   $��2��6:   $��10,15q�6G   �� 5   
   -   5        $ logonTextBlock��5      $��2��6,   $��1��6<   $��注册��6I   $
��Left=�6S   $��Center=�6n   �� 5   
   -   5        $ findTextBlock��5      $��2��6+   $��2��6;   $��找回密码��6H   $
��Left=�6T   $��Center=�6o   � 5   
   $��1��6   $��3��6    5       �� 5!      $	��35* �6    �� 5"      $	��54* �6     5$      �� 5%      $
��141* �6#   �� 5&      $
��142* �6#   .+�5(      � -   5         �Name$ 
loadButton��5(      $��2��6.   $��25��6B   $y�Hidden=�6N   �� 5)      -	   5         ��Name$ signInButton��5)      $��登录��6,   $��1��6:   $��25��6G   $��60��6S   6^   �� 5*      -
   5        $ noButton��5*      $��取消��6'   $��1��64   $��1��6A   $��25��6Q   $��60��6]   5+      5,      5-      