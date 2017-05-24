object Form4: TForm4
  Left = 0
  Top = 0
  AutoSize = True
  BorderIcons = []
  ClientHeight = 224
  ClientWidth = 573
  Color = clWindow
  TransparentColorValue = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 2
    Top = 199
    Width = 121
    Height = 25
    Cursor = crHandPoint
    Hint = #1042#1099#1093#1086#1076' '#1074' '#1086#1082#1085#1086' '#1087#1088#1086#1074#1077#1088#1082#1080' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    Caption = #1042#1099#1093#1086#1076
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnClick = Button1Click
  end
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 563
    Height = 73
    Align = alTop
    BiDiMode = bdLeftToRight
    Color = clBtnHighlight
    DragCursor = crHandPoint
    ParentBiDiMode = False
    ParentBackground = False
    TabOrder = 1
    ExplicitWidth = 540
    object Label1: TLabel
      Left = 2
      Top = 1
      Width = 125
      Height = 25
      Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
    end
    object Panel4: TPanel
      Left = 427
      Top = 32
      Width = 140
      Height = 40
      BorderStyle = bsSingle
      TabOrder = 0
    end
    object Panel3: TPanel
      Left = 286
      Top = 32
      Width = 140
      Height = 40
      BorderStyle = bsSingle
      TabOrder = 1
    end
    object Panel2: TPanel
      Left = 144
      Top = 32
      Width = 140
      Height = 40
      BorderStyle = bsSingle
      TabOrder = 2
    end
    object Panel1: TPanel
      Left = 0
      Top = 32
      Width = 143
      Height = 40
      BorderStyle = bsSingle
      TabOrder = 3
    end
    object Button2: TButton
      Left = 144
      Top = 1
      Width = 140
      Height = 25
      Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1089#1090#1072#1090#1080#1089#1090#1080#1082#1091
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      Visible = False
      OnClick = Button2Click
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 79
    Width = 573
    Height = 114
    BorderStyle = bsSingle
    Color = clCream
    ParentBackground = False
    TabOrder = 2
    object Label2: TLabel
      Left = 0
      Top = 0
      Width = 174
      Height = 19
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1090#1088#1077#1085#1080#1088#1086#1074#1082#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Button4: TButton
      Left = 282
      Top = 42
      Width = 105
      Height = 36
      Cursor = crHandPoint
      Hint = #1053#1072#1095#1072#1090#1100' '#1090#1088#1077#1085#1080#1088#1086#1074#1082#1091' '#1089' '#1091#1082#1072#1079#1072#1085#1085#1099#1084' '#1091#1088#1086#1074#1085#1077#1084' '#1089#1083#1086#1078#1085#1086#1089#1090#1080
      Caption = #1053#1072#1095#1072#1090#1100
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = Button4Click
    end
    object Panel7: TPanel
      Left = -2
      Top = 25
      Width = 267
      Height = 72
      BorderStyle = bsSingle
      Color = clMoneyGreen
      ParentBackground = False
      TabOrder = 1
      object Label3: TLabel
        Left = 1
        Top = 1
        Width = 171
        Height = 16
        Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1083#1086#1078#1085#1086#1089#1090#1100' '#1090#1077#1082#1089#1090#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object RadioButton1: TRadioButton
        Left = 178
        Top = 1
        Width = 46
        Height = 17
        Hint = #1053#1077' '#1076#1086#1083#1078#1085#1086' '#1074#1086#1079#1085#1080#1082#1085#1091#1090#1100' '#1087#1088#1086#1073#1083#1077#1084
        Caption = #1051#1077#1075#1082#1086
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 178
        Top = 24
        Width = 54
        Height = 17
        Hint = #1042#1086#1079#1084#1086#1078#1085#1086' '#1091#1089#1090#1072#1085#1077#1090#1077' '#1087#1077#1095#1072#1090#1072#1090#1100
        Caption = #1057#1088#1077#1076#1085#1077
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 178
        Top = 47
        Width = 66
        Height = 17
        Hint = #1069#1082#1089#1090#1088#1077#1084#1072#1083#1100#1085#1086' '#1084#1085#1086#1075#1086' '#1087#1077#1095#1072#1090#1072#1090#1100'! '#1059#1078#1072#1089'!'
        Caption = #1057#1083#1086#1078#1085#1086
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = RadioButton3Click
      end
    end
  end
  object Button3: TButton
    Left = 527
    Top = 199
    Width = 28
    Height = 25
    Caption = 'Button3'
    TabOrder = 3
    Visible = False
    OnClick = Button3Click
  end
end
