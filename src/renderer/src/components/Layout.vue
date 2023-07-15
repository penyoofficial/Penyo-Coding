<script lang="ts">
import { ElRow, ElCol, ElMenu, ElMenuItem } from 'element-plus'
import CoinThrower from '@renderer/views/CoinThrower.vue'
import DiceThrower from '@renderer/views/DiceThrower.vue'
import PokerPicker from '@renderer/views/PokerPicker.vue'
import UnionLottoCodeGenerator from '@renderer/views/UnionLottoCodeGenerator.vue'
import IDCodeGenerator from '@renderer/views/IDCodeGenerator.vue'

interface EventType {
  /** 显示名 */
  displayName: string
  /** 内部名 */
  name: string
}

export default {
  data(): {
    /** 事件类型 */
    eventTypes: EventType[],
    /** 所选中的事件 */
    chosenEvent: EventType["name"]
  } {
    return {
      eventTypes: [
        { displayName: "硬币抛掷", name: "CoinThrower" },
        { displayName: "骰子抛掷", name: "DiceThrower" },
        { displayName: "扑克牌抽取", name: "PokerPicker" },
        { displayName: "双色球号码生成", name: "UnionLottoCodeGenerator" },
        { displayName: "身份证号码生成", name: "IDCodeGenerator" },
      ],
      chosenEvent: "0"
    }
  },
  components: {
    ElRow,
    ElCol,
    ElMenu,
    ElMenuItem,
    CoinThrower,
    DiceThrower,
    PokerPicker,
    UnionLottoCodeGenerator,
    IDCodeGenerator
  },
  methods: {
    changeEvent(index: string) {
      this.chosenEvent = index
    }
  }
}
</script>

<template>
  <el-row>
    <el-col :span="6">
      <el-menu id="e-selector" @select="changeEvent" :default-active="chosenEvent">
        <el-menu-item v-for="(et, i) in eventTypes" :index="`${i}`">
          <span>{{ et.displayName }}</span>
        </el-menu-item>
      </el-menu>
    </el-col>
    <el-col :span="18">
      <div id="main-op-area">
        <component :is="eventTypes[parseInt(chosenEvent)].name"></component>
      </div>
    </el-col>
  </el-row>
</template>

<style scoped>
#main-op-area {
  padding: 2em;
}
</style>