//
//  MainViewController.m
//  WYBasisKit
//
//  Created by  jacke-xu on 2018/6/19.
//  Copyright © 2018年 jacke-xu. All rights reserved.
//

#import "MainViewController.h"
#import "TestLableViewController.h"
#import "TestWebViewViewController.h"
#import "TestTextViewViewController.h"
#import "TestTextFieldViewController.h"
#import "TestTUIButtonViewController.h"
#import "TestBoolJudgeViewController.h"
#import "TestLoadingStateViewController.h"

@interface MainViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, weak) UITableView *tableView;

@end

@implementation MainViewController

- (void)viewWillAppear:(BOOL)animated {
    
    [super viewWillAppear:YES];
    
    self.navigationController.titleColor = [UIColor yellowColor];
    self.navigationController.titleFont = [UIFont boldSystemFontOfSize:20];
    self.navigationController.barBackgroundColor = [UIColor greenColor];
    //self.navigationController.barBackgroundImage = [UIImage imageNamed:@"test"];
    self.navigationController.barReturnButtonImage = [UIImage imageNamed:@"返回按钮"];
    self.navigationController.barReturnButtonColor = [UIColor whiteColor];
    [self.navigationController pushControllerBarReturnButtonTitle:@"上一页" navigationItem:self.navigationItem];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationItem.title = @"首页";
    self.tableView.backgroundColor = [UIColor whiteColor];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return [self section].count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    
    return 0.01;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    
    return 0.01;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    return 50;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *cellIndentifier = @"UITableViewCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIndentifier];
    
    if(cell == nil)
    {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIndentifier];
        [tableView cellCutOffLineFromZeroPoint:cell];
    }
    cell.backgroundColor = [UIColor whiteColor];
    cell.textLabel.text = [self section][indexPath.row];
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%ld",(long)indexPath.row];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    UIViewController *vc = nil;
    if(indexPath.row == 0) {
        
        vc = [[TestWebViewViewController alloc]init];
    }
    else if (indexPath.row == 1) {
        
        vc = [[TestLableViewController alloc]init];
    }
    else if (indexPath.row == 2) {
        
        vc = [[TestTextViewViewController alloc]init];
    }
    else if (indexPath.row == 3) {
        
        vc = [[TestTextFieldViewController alloc]init];
    }
    else if (indexPath.row == 4) {
        
        vc = [[TestTUIButtonViewController alloc]init];
    }
    else if (indexPath.row == 5) {
        
        vc = [[TestBoolJudgeViewController alloc]init];
    }
    else if (indexPath.row == 6) {
        
        vc = [[TestLoadingStateViewController alloc]init];
    }
    vc.navigationItem.title = [self section][indexPath.row];
    [self.navigationController pushViewController:vc animated:YES];
}

- (NSArray *)section {
    
    NSArray *sectionTitleAry = @[@"WKWebView",@"UILable",@"UITextView",@"UITextField",@"UIButton",@"BoolJudge",@"LoadingState"];
    
    return sectionTitleAry;
}

- (UITableView *)tableView {
    
    if(_tableView == nil) {
        
        UITableView *tableview = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, screenWidth, screenHeight-navViewHeight) style:UITableViewStyleGrouped];
        tableview.delegate = self;
        tableview.dataSource = self;
        [tableview forbiddenSelfSizing];
        tableview.tableFooterView = [[UIView alloc]init];
        
        [self.view addSubview:tableview];
        
        _tableView = tableview;
    }
    
    return _tableView;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
