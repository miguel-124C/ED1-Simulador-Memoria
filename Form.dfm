object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 900
  ClientWidth = 1112
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnPaint = FormPaint
  TextHeight = 15
  object Label6: TLabel
    Left = 430
    Top = 860
    Width = 72
    Height = 32
    Caption = 'Libre 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Button1: TButton
    Left = 413
    Top = 10
    Width = 129
    Height = 35
    Caption = 'Crear memoria'
    TabOrder = 0
    OnClick = OnCreateMemoria
  end
  object Panel2: TPanel
    Left = 8
    Top = 10
    Width = 399
    Height = 840
    TabOrder = 1
    object Label1: TLabel
      Left = 11
      Top = 215
      Width = 65
      Height = 21
      Caption = 'Direccion'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 95
      Top = 215
      Width = 13
      Height = 21
      Caption = 'Id'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 217
      Top = 215
      Width = 36
      Height = 21
      Caption = 'Valor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 11
      Top = 408
      Width = 65
      Height = 21
      Caption = 'Direccion'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 98
      Top = 408
      Width = 13
      Height = 21
      Caption = 'Id'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Button2: TButton
      Left = 11
      Top = 32
      Width = 129
      Height = 35
      Caption = 'Pedir espacio'
      TabOrder = 0
      OnClick = OnPedirEspacio
    end
    object EEspacioName: TEdit
      Left = 146
      Top = 32
      Width = 129
      Height = 35
      TabOrder = 1
    end
    object Button3: TButton
      Left = 11
      Top = 86
      Width = 129
      Height = 35
      Caption = 'Liberar espacio'
      TabOrder = 2
      OnClick = OnLiberarEspacio
    end
    object EEspacioALiberar: TEdit
      Left = 146
      Top = 86
      Width = 129
      Height = 35
      TabOrder = 3
    end
    object Button5: TButton
      Left = 11
      Top = 154
      Width = 129
      Height = 35
      Caption = 'Poner dato'
      TabOrder = 4
      OnClick = OnPonerDato
    end
    object EDirDato: TEdit
      Left = 11
      Top = 242
      Width = 81
      Height = 39
      TabOrder = 5
    end
    object EIdDato: TEdit
      Left = 95
      Top = 242
      Width = 116
      Height = 39
      TabOrder = 6
    end
    object EValorDato: TEdit
      Left = 217
      Top = 242
      Width = 139
      Height = 39
      TabOrder = 7
    end
    object Button4: TButton
      Left = 11
      Top = 355
      Width = 129
      Height = 35
      Caption = 'Mostrar memoria'
      TabOrder = 8
      OnClick = OnMostrarMemoria
    end
    object EShowDir: TEdit
      Left = 11
      Top = 435
      Width = 81
      Height = 35
      TabOrder = 9
    end
    object EShowId: TEdit
      Left = 98
      Top = 435
      Width = 113
      Height = 35
      TabOrder = 10
    end
    object Panel1: TPanel
      Left = 0
      Top = 499
      Width = 399
      Height = 100
      TabOrder = 11
      Visible = False
      object Edit1: TEdit
        Left = 8
        Top = 38
        Width = 57
        Height = 23
        Enabled = False
        TabOrder = 0
      end
      object Edit2: TEdit
        Left = 64
        Top = 38
        Width = 130
        Height = 23
        Enabled = False
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 192
        Top = 38
        Width = 138
        Height = 23
        Enabled = False
        TabOrder = 2
      end
      object Edit4: TEdit
        Left = 328
        Top = 38
        Width = 57
        Height = 23
        Enabled = False
        TabOrder = 3
      end
      object Edit5: TEdit
        Left = 64
        Top = 17
        Width = 130
        Height = 23
        Enabled = False
        TabOrder = 4
        Text = 'Dato'
      end
      object Edit6: TEdit
        Left = 192
        Top = 17
        Width = 138
        Height = 23
        Enabled = False
        TabOrder = 5
        Text = 'Id'
      end
      object Edit7: TEdit
        Left = 328
        Top = 17
        Width = 57
        Height = 23
        Enabled = False
        TabOrder = 6
        Text = 'Link'
      end
      object Edit8: TEdit
        Left = 8
        Top = 17
        Width = 57
        Height = 23
        Enabled = False
        TabOrder = 7
        Text = 'Direcci'#243'n'
      end
      object Button6: TButton
        Left = 310
        Top = 67
        Width = 75
        Height = 25
        Caption = 'Ocultar'
        TabOrder = 8
        OnClick = Button6Click
      end
    end
    object Button7: TButton
      Left = 8
      Top = 733
      Width = 75
      Height = 25
      Caption = 'Button7'
      TabOrder = 12
    end
    object Button8: TButton
      Left = 103
      Top = 733
      Width = 75
      Height = 25
      Caption = 'Button7'
      TabOrder = 13
    end
  end
end
