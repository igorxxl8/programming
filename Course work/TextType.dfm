object Form5: TForm5
  Left = 0
  Top = 0
  AutoSize = True
  BorderIcons = []
  Caption = #1053#1072#1073#1086#1088' '#1090#1077#1082#1089#1090#1072' '
  ClientHeight = 360
  ClientWidth = 662
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 103
    Top = 8
    Width = 8
    Height = 13
  end
  object Label2: TLabel
    Left = 112
    Top = 336
    Width = 57
    Height = 23
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 505
    Top = 5
    Width = 44
    Height = 13
    Caption = #1054#1096#1080#1073#1086#1082':'
  end
  object Label4: TLabel
    Left = 297
    Top = 8
    Width = 52
    Height = 13
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100':'
  end
  object Label5: TLabel
    Left = 397
    Top = 306
    Width = 50
    Height = 13
    Caption = #1055#1088#1086#1075#1088#1077#1089#1089':'
  end
  object Button1: TButton
    Left = 0
    Top = 335
    Width = 97
    Height = 25
    Cursor = crHandPoint
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 0
    Top = 305
    Width = 247
    Height = 25
    Enabled = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    Text = #1047#1076#1077#1089#1100' '#1073#1091#1076#1077#1090#1077' '#1085#1072#1073#1080#1088#1072#1090#1100' '#1090#1077#1082#1089#1090
    OnChange = Edit1Change
  end
  object Приступить: TButton
    Left = 0
    Top = 0
    Width = 97
    Height = 25
    Cursor = crHandPoint
    Caption = #1055#1088#1080#1089#1090#1091#1087#1080#1090#1100
    TabOrder = 2
    OnClick = ПриступитьClick
  end
  object Panel1: TPanel
    Left = 245
    Top = 306
    Width = 132
    Height = 18
    Color = clLime
    ParentBackground = False
    TabOrder = 3
  end
  object Panel2: TPanel
    Left = 355
    Top = 0
    Width = 96
    Height = 25
    BorderStyle = bsSingle
    Color = clWindow
    ParentBackground = False
    TabOrder = 4
  end
  object Panel3: TPanel
    Left = 565
    Top = 0
    Width = 97
    Height = 25
    BorderStyle = bsSingle
    Color = clWindow
    ParentBackground = False
    TabOrder = 5
  end
  object ProgressBar1: TProgressBar
    Left = 453
    Top = 306
    Width = 209
    Height = 17
    BackgroundColor = clWindow
    TabOrder = 6
  end
  object Button2: TButton
    Left = 397
    Top = 325
    Width = 28
    Height = 28
    Caption = 'Button2'
    Enabled = False
    TabOrder = 7
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 371
    Top = 325
    Width = 28
    Height = 28
    Caption = 'Button2'
    Enabled = False
    TabOrder = 8
    Visible = False
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 337
    Top = 325
    Width = 28
    Height = 28
    Caption = 'Button2'
    Enabled = False
    TabOrder = 9
    Visible = False
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 303
    Top = 325
    Width = 28
    Height = 28
    Caption = 'Button2'
    Enabled = False
    TabOrder = 10
    Visible = False
    OnClick = Button5Click
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 31
    Width = 662
    Height = 269
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Lines.Strings = (
      'RichEdit1')
    ParentFont = False
    TabOrder = 11
    Zoom = 100
    OnClick = RichEdit1Click
    OnEnter = RichEdit1Enter
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 472
    Top = 328
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 440
    Top = 324
  end
  object ApplicationEvents1: TApplicationEvents
    OnShortCut = ApplicationEvents1ShortCut
    Left = 528
    Top = 328
  end
end
